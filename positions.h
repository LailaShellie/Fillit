/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 15:06:15 by lshellie          #+#    #+#             */
/*   Updated: 2019/05/19 15:06:16 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

#ifndef FILLIT_POSITIONS_H
#define FILLIT_POSITIONS_H

typedef struct			s_positions
{
	unsigned int		base;
	unsigned int		*shape;
	struct s_positions	*next;
	struct s_positions	*prev;
	char 				c;
	int 				status;
}						t_positions;

t_positions				*make_positions(t_positions **positions, unsigned int *shape, unsigned int base);
void					free_pos_next(t_positions **pos);
void					free_pos_prev(t_positions *pos);
t_positions				**make_all_positions(unsigned int **shapes,
		unsigned int base, unsigned int num);

#endif
