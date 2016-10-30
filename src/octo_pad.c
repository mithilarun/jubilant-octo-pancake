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

int
octo_pad_msg(octo_mesg_t *msg)
{
	int	m_len, rem, shift;
	int	*iter = msg->msg;
	char 	*tmp;
	m_len = (msg->size * 8);
	if(m_len % 32 == 0) {
		tmp = msg->msg + msg->size + 1;
		tmp[0] = 0x80;
	} else {
		rem = m_len % 32;
		shift = 0x1;
		for(int i = 0;i < (m_len / 32);i++){
			iter = iter + 1;
		}
		shift = octo_bit_shl(shift, (32 - rem));
		octo_bit_or(*iter, shift);
	}
	iter = (msg->msg + msg->buf_sz) - 2;
	*iter = (int64_t)m_len;

}
	
	 
