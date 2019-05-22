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
GCC = gcc -Wall -Wextra -Werror
HEADERS = ft_fillit.h positions.h
LIB = -L. libft/libft.a
all:
	 $(GCC) -c $(HEADERS) $(SRC)
clean:
	rm a.out
re: clean all
