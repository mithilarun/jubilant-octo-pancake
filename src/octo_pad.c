/*
 * Copyright (C) 2016, Ambarish Ravindran
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
octo_pad_msg(octo_mesg_t *msg)
{
	char		*iter;
	uint64_t	*lptr;
	uint64_t	l;

	iter = msg->msg + msg->size;
	*iter = (uint64_t)128;	// 128 is 10000000 in binary

	iter = msg->msg + msg->buf_sz - 8;	// Need to store <l>

	l = (uint64_t)msg->size * 8;
	lptr = (uint64_t *)iter;
	*lptr = l;
}
