#ifndef UTILS_H
#define UTILS_H

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

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OCTO_BUF_SZ 2048
#define OCTO_MSG_BLK_SZ 512

typedef unsigned int uint_t;

typedef struct {
	size_t	size;
	char	*msg;
} octo_mesg_t;

uint_t octo_bit_or(const uint_t a, const uint_t b);
uint_t octo_bit_and(const uint_t a, const uint_t b);
uint_t octo_bit_xor(const uint_t a, const uint_t b);
uint_t octo_bit_rotl(const uint_t a, uint_t pos);
uint_t octo_bit_rotr(const uint_t a, uint_t pos);
uint_t octo_bit_shl(const uint_t a, uint_t pos);
uint_t octo_bit_shr(const uint_t a, uint_t pos);
uint_t octo_bit_compl(const uint_t a);

uint_t octo_ch(const uint_t a, const uint_t b, const uint_t c);
uint_t octo_maj(const uint_t a, const uint_t b, const uint_t c);
uint_t octo_sig1(const uint_t x);
uint_t octo_sig2(const uint_t x);
uint_t octo_sig3(const uint_t x);
uint_t octo_sig4(const uint_t x);

void octo_read_msg(octo_mesg_t *msg);
void *octo_malloc(size_t size);
int main(int argc, char *argv[]);

#endif /* UTILS_H */
