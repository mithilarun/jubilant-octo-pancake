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

int bit_or(const int a, const int b);
int bit_and(const int a, const int b);
int bit_xor(const int a, const int b);
int bit_rotl(const int a, int pos);
int bit_rotr(const int a, int pos);
int bit_compl(const int a);

int main(int argc, char *argv[]);

#endif /* UTILS_H */