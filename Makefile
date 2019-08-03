# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lshellie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/06 20:04:07 by lshellie          #+#    #+#              #
#    Updated: 2019/08/03 12:22:11 by lshellie         ###   ########.fr        #
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
NAME = fillit
LIB = ./libft/libft.a
all: $(NAME)
$(NAME): $(OFILES) $(LIB)
	$(GCC) -L. $(LIB) -o $(NAME) $(OFILES)
$(LIB):
	make -C ./libft
%.o: %.c
	gcc -c $<
clean:
	rm -rf $(OFILES)
	make clean -C ./libft
fclean: clean
	rm -rf $(NAME)
	make clean -C ./libft
	rm -rf ./libft/libft.a
re: clean all
