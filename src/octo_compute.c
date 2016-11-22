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

#include "octo_const.h"
#include "octo_utils.h"

void 
octo_hash_compute(octo_mesg_t *msg)
{
	uint32_t	*wt;
	int		N;
	int		i, t, iter = 0, count;
	uint32_t	a, b, c, d, e, f, g, h;
	uint32_t	T1, T2;

	wt = (uint32_t *)malloc(sizeof(uint32_t)*64);
	N = (msg->buf_sz/64);


	for(i = 0; i < N; i++)
	{
		count  = 0;
		do {
			wt[count] = msg->msg[iter];
			iter++;
			count++;
		} while((iter % 16) != 0);

		for (count = 16; count < 64; count++) {
			wt[count] = octo_sig4(wt[count-2]) + wt[count-7] +
			    octo_sig3(wt[count-15]) + wt[count-16];
		}

		a = H0;
		b = H1;
		c = H2;
		d = H3;
		e = H4;
		f = H5;
		g = H6;
		h = H7;

		for(t = 0; t < 64; t++){
			T1 = h + octo_sig2(e) + octo_ch(e, f, g) + K[t] + wt[t];
			T2 = octo_sig1(a) + octo_maj(a, b, c);
			h = g;
			g = f;
			f = e;
			e = d + T1; 
			d = c;
			c = b;
			b = a;
			a = T1 + T2;
		}

		H0 = a + H0;
		H1 = b + H1;
		H2 = c + H2;
		H3 = d + H3;
		H4 = e + H4;
		H5 = f + H5;
		H6 = g + H6;
		H7 = h + H7;
	}
	//printf("%" PRIu32 "\n%" PRIu32 "\n%" PRIu32 "\n%" PRIu32 "\n%" PRIu32 "\n%" PRIu32 "\n%" PRIu32 "\n%" PRIu32 "\n", H0, H1, H2, H3, H4, H5, H6, H7);
	printf("%X\n%X\n%X\n%X\n%X\n%X\n%X\n%X\n", H0, H1, H2, H3, H4, H5, H6, H7);
}


