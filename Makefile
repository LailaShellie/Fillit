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

SRC = main.c ft_int.c check_file.c ft_shape.c convert_shape.c

all:
	gcc -Wall -Wextra -Werror -I. ft_fillit.h -L. libft/libft.a $(SRC)
clean:
	rm a.out
re: clean all
