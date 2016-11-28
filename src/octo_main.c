/*
 * Copyright (C) 2016, Mithil Arun
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "octo_utils.h"

void
octo_read_msg(octo_mesg_t *msg)
{
	/*
	 * wc_cmd has size greater than OCTO_BUF_SZ so as to accomodate the
	 * length of the "wc" command as well.
	 */
	char	wc_cmd[OCTO_BUF_SZ + 30];

	char	fname[OCTO_BUF_SZ], wc_out[OCTO_BUF_SZ] = "";
	FILE	*fp, *mfile;
	int	count = 0, i;
	char	*tok, *tmp;

	printf("Enter file name\n");
	if (scanf("%s", fname) == EOF) {
		printf("Error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	// Need to get size of data in file (# chars)
	if (snprintf(wc_cmd, sizeof (wc_cmd), "/usr/bin/wc -c %s", fname)
	    < 0) {
		printf("Failed to get size of file.\n.");
		exit(EXIT_FAILURE);
	}

	fp = popen(wc_cmd, "r");
	if (fp == NULL) {
		printf("Failed to fetch size of file\n. Exiting.\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(wc_out, (int)sizeof(wc_out) - 1, fp) != NULL);
	if (pclose(fp) == -1) {
		printf("Error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	tok = strtok(wc_out, " ");
	if (tok == NULL) {
		printf("Failed to parse char count\n");
		exit(EXIT_FAILURE);
	}
	msg->size = (size_t)atoi(tok);

	for (i = 0; i < 64; i++) {
		if ((msg->size + i) % 64 == 0) {
			break;
		}
	}
	msg->buf_sz = msg->size + i;

	assert(msg->buf_sz >= msg->size);

	msg->msg = (char *)octo_malloc(msg->buf_sz);

	tmp = msg->msg;
	mfile = fopen(fname, "r");
	if (mfile == NULL) {
		printf("Failed to open file %s\n", fname);
		exit(EXIT_FAILURE);
	}
	while (fgets(tmp, (int)msg->size - count, mfile) != NULL) {
		count += strlen(tmp) - 1;
		tmp = tmp + strlen(tmp);
	}

	if (fclose(mfile) != 0) {
		printf("Error: %s", strerror(errno));
		exit(EXIT_FAILURE);
	}
}




int
main(void)
{
	octo_mesg_t	*msg;

	msg = (octo_mesg_t *)octo_malloc(sizeof (octo_mesg_t));
	octo_read_msg(msg);
	octo_pad_msg(msg);
	octo_hash_compute(msg);

	/*
	 * Clean up any allocated memory
	 */
	free(msg->msg);
	free(msg);
	return (0);
}
