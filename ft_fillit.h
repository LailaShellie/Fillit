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
# define __FT_FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"
# define BUFF_SIZE 546
# define MAX_BASE 32

typedef struct			s_positions
{
	unsigned int		base;
	unsigned int		*shape;
	struct s_positions	*next;
	struct s_positions	*prev;
	char				c;
	unsigned int		status;
	unsigned int		active;
	unsigned int		used;
}						t_positions;

typedef struct			s_lst
{
	t_positions			*pos;
	struct s_lst		*next;
	struct s_lst		*prev;
	unsigned int		same;
}						t_lst;

typedef struct			s_int
{
	unsigned int		num;
	unsigned int		line;
	unsigned int		i;
	unsigned int		link;
	unsigned int		num_of_links;
}						t_int;
t_positions				*make_positions(t_positions **positions,
		unsigned int *shape, unsigned int base, char c);
void					free_pos_next(t_positions **pos);
int						read_file(const int fd, char **buf);
void					make_bits(char *buf, unsigned int num);
void					set_bits(unsigned int *shape, char *buf);
unsigned int			check_slot(const char *buf,
		unsigned int i, unsigned int line, char c);
int						check_file(const char *buf);
void					init_struct(t_int *a,
		unsigned int line, unsigned int i);
unsigned int			**move_to_zero(unsigned int **shape,
		unsigned int base, unsigned int num);
unsigned int			make_matrix(unsigned int ***shapes, unsigned int num);
unsigned int			**copy_shapes(unsigned int **new_base,
		unsigned int **shapes, unsigned int base, unsigned int num);
unsigned int			**cut_shapes(unsigned int ***shapes,
		unsigned int base, unsigned int num);
unsigned int			**delete_shapes(unsigned int **shapes,
		unsigned int num);
unsigned int			**allocate(unsigned int num, unsigned int base);
void					show_shapes(unsigned int **shapes,
		unsigned int base, unsigned int num);
unsigned int			check_y_line(const unsigned int *shape,
		unsigned int base, unsigned int x);
void					move_down(unsigned int *shape,
		unsigned int base, unsigned int n);
void					move_right(unsigned int *shape,
		unsigned int base, unsigned int n);
void					move_left(unsigned int *shape,
		unsigned int base, unsigned int n);
void					dup_shapes(unsigned int *dst,
		const unsigned int *src, unsigned int base);
int						move_next(unsigned int *shape, unsigned int base);
int						check_traversal(unsigned int *shape,
		unsigned int *shp, unsigned int base);
unsigned int			check_x_line(unsigned int *shapes,
		unsigned int base);
void					find_traversal(t_lst *lst, t_positions *pos,
		unsigned int n);
t_lst					*make_all_positions(unsigned int **shapes,
		unsigned int base, unsigned int num);
t_lst					*make_lst(t_lst *prev);
int						find_solution(t_lst *lst);
void					free_lst(t_lst **lst);
int						solution(t_lst **lst, unsigned int ***shapes,
		unsigned int *base, unsigned int num);
void					show_all_pos_unactive(t_lst *lst,
		unsigned int base);
void					clear_used(t_lst *lst);
void					make_new_base(unsigned int ***shapes,
		unsigned int *base, unsigned int num);
void					show_all(t_lst *lst, unsigned int base);
int						compare_shapes(unsigned int *shape,
		unsigned int *shp);

#endif
