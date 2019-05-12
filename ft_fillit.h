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

typedef struct		s_int
{
	int				num;
	int				line;
	int				i;
	int				link;
	int				num_of_links;
}					t_int;
int					read_file(const int fd, char **buf);
void 				make_bits(char *buf, int num);
void				set_bits(unsigned long int *shape, char *buf);
int					check_slot(const char *buf, int i, int line, char c);
int					check_file(const char *buf);
void				init_struct(t_int *a, int line, int i);
void				move_to_zero(unsigned long int **shape, int num);

#endif
