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

void *
octo_malloc(size_t size)
{
	void *tmp;

	tmp = (void *)malloc(size);
	bzero(tmp, size);
	return (tmp);
}

uint32_t
octo_ch(const uint32_t a, const uint32_t b, const uint32_t c)
{
	uint32_t	res;

	res = octo_bit_xor(octo_bit_and(a, b),
	    octo_bit_and(octo_bit_compl(a), c));

	return (res);
}

uint32_t
octo_maj(const uint32_t a, const uint32_t b, const uint32_t c)
{
	uint32_t	res, tmp;

	tmp = octo_bit_xor(octo_bit_and(a, b), octo_bit_and(a, c));

	res = octo_bit_xor(tmp, octo_bit_and(b, c));

	return (res);
}

uint32_t
octo_sig1(const uint32_t x)
{
	uint32_t	res, tmp;

	tmp = octo_bit_xor(octo_bit_rotr(x, 2), octo_bit_rotr(x, 13));

	res = octo_bit_xor(tmp, octo_bit_rotr(x, 22));

	return (res);
}

uint32_t
octo_sig2(const uint32_t x)
{
	uint32_t	res, tmp;

	tmp = octo_bit_xor(octo_bit_rotr(x, 6), octo_bit_rotr(x, 11));

	res = octo_bit_xor(tmp, octo_bit_rotr(x, 25));

	return (res);
}

uint32_t
octo_sig3(const uint32_t x)
{
	uint32_t	res, tmp;

	tmp = octo_bit_xor(octo_bit_rotr(x, 7), octo_bit_rotr(x, 18));

	res = octo_bit_xor(tmp, octo_bit_shr(x, 3));

	return (res);
}

uint32_t
octo_sig4(const uint32_t x)
{
	uint32_t	res, tmp;

	tmp = octo_bit_xor(octo_bit_rotr(x, 17), octo_bit_rotr(x, 19));

	res = octo_bit_xor(tmp, octo_bit_shr(x, 10));

	return (res);
}
