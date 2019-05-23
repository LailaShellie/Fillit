# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lshellie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/06 20:04:07 by lshellie          #+#    #+#              #
#    Updated: 2019/05/07 15:33:17 by lshellie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c ft_int.c check_file.c make_bits.c move_shapes.c \
    matrix.c shape.c check_shapes.c positions.c parse_lists.c \
    free_pos.c solution.c print.c
OFILES = main.o ft_int.o check_file.o make_bits.o move_shapes.o \
    matrix.o shape.o check_shapes.o positions.o parse_lists.o \
    free_pos.o solution.o print.o
GCC = gcc -Wall -Wextra -Werror
HEADERS = ft_fillit.h
LIB = -L. libft/libft.a
all:
	 gcc -c $(HEADERS) $(SRC)
	 $(GCC) -o fillit $(OFILES) $(LIB)
	 rm -rf $(OFILES)
clean:
	rm -rf $(OFILES)
re: clean all
