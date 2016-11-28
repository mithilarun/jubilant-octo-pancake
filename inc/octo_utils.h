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

#include <assert.h>
#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define OCTO_BUF_SZ 2048
#define OCTO_MSG_BLK_SZ 512

typedef struct octo_mesg_s {
	size_t	size;
	size_t	buf_sz;
	char	*msg;
} octo_mesg_t;

uint32_t octo_bit_or(uint32_t a, uint32_t b);
uint32_t octo_bit_and(uint32_t a, uint32_t b);
uint32_t octo_bit_xor(uint32_t a, uint32_t b);
uint32_t octo_bit_rotl(uint32_t a, uint32_t pos);
uint32_t octo_bit_rotr(uint32_t a, uint32_t pos);
uint32_t octo_bit_shl(uint32_t a, uint32_t pos);
uint32_t octo_bit_shr(uint32_t a, uint32_t pos);
uint32_t octo_bit_compl(uint32_t a);

uint32_t octo_ch(const uint32_t a, const uint32_t b, const uint32_t c);
uint32_t octo_maj(const uint32_t a, const uint32_t b, const uint32_t c);
uint32_t octo_sig1(const uint32_t x);
uint32_t octo_sig2(const uint32_t x);
uint32_t octo_sig3(const uint32_t x);
uint32_t octo_sig4(const uint32_t x);

void octo_read_msg(octo_mesg_t *msg);
void octo_hash_compute(octo_mesg_t *msg);
void *octo_malloc(size_t size);
int main(void);
void octo_pad_msg(octo_mesg_t *msg);
#endif /* UTILS_H */
