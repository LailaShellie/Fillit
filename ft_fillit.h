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
# include "positions.h"

# define BUFF_SIZE 546
# define MAX_BASE 32

typedef struct 		s_form
{
	unsigned int	hight;
	unsigned int	width;
}					t_form;

typedef struct		s_iter
{
	unsigned int	y;
	unsigned int	x;
	unsigned int	i;
	unsigned int	j;
	unsigned int	num;
}					t_iter;

typedef struct		s_int
{
	unsigned int	num;
	unsigned int	line;
	unsigned int	i;
	unsigned int	link;
	unsigned int	num_of_links;
}					t_int;
void				init_iter(t_iter *a);
int					read_file(const int fd, char **buf);
void 				make_bits(char *buf, unsigned int num);
void				set_bits(unsigned int *shape, char *buf);
unsigned int		check_slot(const char *buf, unsigned int i,unsigned int line, char c);
int					check_file(const char *buf);
void				init_struct(t_int *a, unsigned int line, unsigned int i);
void				move_to_zero(unsigned int **shape, unsigned int base, unsigned int num);
unsigned int 		make_matrix(unsigned int ***shapes, unsigned int num);
unsigned int		**copy_shapes(unsigned int **new_base, unsigned int **shapes,
		unsigned int base, unsigned int num);
unsigned int		**cut_shapes(unsigned int ***shapes, unsigned int base, unsigned int num);
unsigned int		**delete_shapes(unsigned int **shapes, unsigned int num);
unsigned int		**allocate(unsigned int num, unsigned int base);
void				show_shapes(unsigned int **shapes, unsigned int base,unsigned int num);
unsigned int		check_y_line(const unsigned int *shape, unsigned int base, unsigned int x);
void				move_down(unsigned int *shape, unsigned int base, unsigned int n);
void				move_right(unsigned int *shape, unsigned int base, unsigned int n);
void				move_left(unsigned int *shape, unsigned int base, unsigned int n);
void				dup_shapes(unsigned int *dst,const unsigned int *src,
					   unsigned int base);
void				get_form(const unsigned int *shapes, t_form	*form);
int 				move_next(unsigned int *shape,
				 unsigned int base);
int 				check_traversal(unsigned int *shape,
						   unsigned int *shp, unsigned int base);
unsigned int		check_x_line(unsigned int *shapes, unsigned int base);

#endif
