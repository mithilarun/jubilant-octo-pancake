#
# Copyright (C) 2016, Mithil Arun
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

CC = gcc
CFLAGS = -Wall -g
INCLUDES = -I../inc

NAME = sha256
VERSION = 0.0.1

SRCS := octo_main.c octo_utils.c octo_pad.c

BINDIR = ../bin/
OBJS := $(addprefix $(BINDIR), $(SRCS:%.c=%.o))

MAIN = $(BINDIR)$(NAME)_$(VERSION)

.PHONY: clean

all: $(MAIN)
	@echo	Compilation completed successfully.

$(MAIN): $(BINDIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS) $(INCLUDES)

$(OBJS): | $(BINDIR)


$(BINDIR)%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BINDIR):
	mkdir -p ../bin

clean:
	$(RM) ../bin/*
	rmdir ../bin/

