/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 15:04:56 by lshellie          #+#    #+#             */
/*   Updated: 2019/05/19 15:04:57 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void		free_pos_next(t_positions **pos)
{
	t_positions		*cur;
	t_positions		*tmp;

	cur = *pos;
	while (cur)
	{
		tmp = cur->next;
		free(cur->shape);
		free(cur);
		cur = cur->next;
		tmp = 0;
	}
	cur = 0;
}

void		free_pos_prev(t_positions *pos)
{
	t_positions		*cur;
	t_positions		*tmp;

	cur = pos;
	while (cur)
	{
		tmp = cur->prev;
		free(cur->shape);
		free(cur);
		cur = tmp;
		tmp = 0;
	}
	cur = 0;
}

t_positions		*new_pos(unsigned int *shape, unsigned int base)
{
	t_positions		*pos;

	if (!(pos = (t_positions *)malloc(sizeof(t_positions))))
		return (0);
	pos->base = base;
	pos->c = 0;
	pos->next = 0;
	pos->prev = 0;
	pos->status = 0;
	pos->shape = (unsigned int *)ft_memalloc(4 * base);
	dup_shapes(pos->shape, shape, base);
	return (pos);
}

t_positions		**make_all_positions(unsigned int **shapes,
		unsigned int base, unsigned int num)
{
	t_positions		**pos;
	t_positions		*start;
	t_int			a;

	pos = (t_positions **)ft_memalloc(num * sizeof(t_positions *));
	init_struct(&a, 0, 0);
	while (a.num < num)
	{
		pos[a.num] = make_positions(&(pos[a.num]), shapes[a.num], base);
		start = pos[a.num];
		while (move_next(shapes[a.num], base) != 0)
		{
			pos[a.num] = make_positions(&(pos[a.num]), shapes[a.num], base);
		}
		while (start)
		{

			show_shapes(&((start)->shape), base, 1);
			(start) = (start)->next;
		}
		printf("\n");
		++a.num;
	}
	return (pos);
}

t_positions		*make_positions(t_positions **positions, unsigned int *shape, unsigned int base)
{
	t_positions *pos;

	pos = new_pos(shape, base);
	if (*positions == 0)
	{
		*positions = pos;
	}
	else if (*positions != 0)
	{
		(*positions)->next = pos;
		pos->prev = *positions;
	}

	return (pos);
}