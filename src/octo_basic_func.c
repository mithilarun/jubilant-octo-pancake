/*
 * Copyright (C) 2016, Mithil Arun, Vineet Mishra, Ambarish Ravindran
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

uint32_t
octo_bit_rotr(uint32_t a, uint32_t b)
{
	a = (((a) >> (b)) | ((a) << (32-(b))));  //Rotate Right

	return (a);
}

uint32_t
octo_bit_rotl(uint32_t a, uint32_t b)
{
	a = (((a) << (b)) | ((a) >> (32-(b))));  //Rotate Left

	return (a);
}

uint32_t
octo_bit_shr(uint32_t a, uint32_t b)
{
	a = ((a) >> (b));                         //Shift Right

	return (a);
}

uint32_t
octo_bit_shl(uint32_t a, uint32_t b)
{
	a = ((a) << (b));                         //Shift Right

	return (a);
}

uint32_t
octo_bit_compl(uint32_t a)
{
	return (~a);
}

uint32_t
octo_bit_or(uint32_t a, uint32_t b)
{
	return (a | b);
}

uint32_t
octo_bit_and(uint32_t a, uint32_t b)
{
	return (a & b);
}

uint32_t
octo_bit_xor(uint32_t a, uint32_t b)
{
	return (a ^ b);
}
