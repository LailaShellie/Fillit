/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:27:48 by lshellie          #+#    #+#             */
/*   Updated: 2019/05/02 19:27:51 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_FILLIT_H
#define __FT_FILLIT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"

# define BUFF_SIZE 546
# define SHAPE_LEN 16

typedef struct		s_shape
{
	int				x[4];
	char 			c;
	int				width;
	int				height;
	int				base;
	int				last;
}					t_shape;
typedef struct		s_int
{
	int				len;
	int				num;
	int				line;
	int				i;
	int				link;
	int				num_of_links;
}					t_int;
t_shape				**make_shapes(int	num, char *buf);
int					read_file(const int fd, char **buf);
void				print(char *s);
int					check_slot(const char *buf, int i, int line, char c);
void				convert_shape(t_shape **shape, int base);
void				fill_shape(char *shp, char *buf);
int					check_file(const char *buf);
t_shape				**free_shapes(t_shape **shapes);
void				init_struct(t_int *a, int line, int i);

#endif
