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
# define MAX_BASE 32

typedef struct		s_shape
{
	unsigned int	base;
	unsigned int	*shapes;
	struct s_shape	*next;
	struct s_shape	*prev;
	char 			c;
	int 			status;
}					t_shape;

typedef struct		s_int
{
	unsigned int	num;
	unsigned int	line;
	unsigned int	i;
	unsigned int	link;
	unsigned int	num_of_links;
}					t_int;
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
void				move_down(unsigned int *shape, unsigned int base);
void				move_right(unsigned int *shape, unsigned int base);
void				move_left(unsigned int *shape, unsigned int base);
int					make_combinations(t_shape **combinations,
							 unsigned int *shape, unsigned int base, char c);
int 				show_combinations(t_shape **combinations, unsigned int base, unsigned int num);
void				free_combinations(t_shape **combinations);

#endif
