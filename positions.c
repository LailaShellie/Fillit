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

t_lst			*make_num_lst(unsigned int num, t_lst *prev)
{
	t_lst			*lst;

	lst = 0;
	if (num)
	{
		lst = make_lst(prev);
		lst->next = make_num_lst(--num, prev);
	}
	return (lst);
}

t_lst			*make_lst(t_lst *prev)
{
	t_lst		*lst;
	if (!(lst = (t_lst *)malloc(sizeof(t_lst))))
		return (0);
	lst->next = 0;
	lst->prev = prev;
	lst->pos = 0;
	return (lst);
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
	pos->active = 0;
	pos->used = 0;
	pos->shape = (unsigned int *)ft_memalloc(4 * base);
	dup_shapes(pos->shape, shape, base);
	return (pos);
}

t_lst		*make_all_positions(unsigned int **shapes,
		unsigned int base, unsigned int num)
{
	t_lst			*lst;
	t_lst			*start;
	t_positions		*cur;
	unsigned int	a;
	char 			c;

	c = 'A';
	a = 0;
	lst = make_num_lst(num, 0);
	start = lst;
	while (lst)
	{
		lst->pos = make_positions(&(lst->pos), shapes[a], base, c);
		cur = lst->pos;
		while (move_next(shapes[a], base) != 0)
			cur = make_positions(&(cur), shapes[a], base, c);
		lst = lst->next;
		++c;
		++a;
	}
	return (start);
}

t_positions		*make_positions(t_positions **positions, unsigned int *shape, unsigned int base, char c)
{
	t_positions *pos;

	pos = new_pos(shape, base);
	pos->c = c;
	if (*positions == 0)
		*positions = pos;
	else if (*positions != 0)
	{
		(*positions)->next = pos;
		pos->prev = *positions;
	}
	return (pos);
}
void			show_all_pos(t_lst *lst, unsigned int base)
{
	t_positions *cur_pos;
	t_lst		*cur_lst;

	cur_lst = lst;
	while (cur_lst)
	{
		cur_pos = cur_lst->pos;
		while (cur_pos)
		{
			if (cur_pos->active == 1)
				show_shapes(&(cur_pos->shape), base, 1);
			cur_pos = cur_pos->next;
		}
		printf("\n");
		cur_lst = cur_lst->next;
	}
}

void			show_all_pos_unactive(t_lst *lst, unsigned int base)
{
	t_positions *cur_pos;
	t_lst		*cur_lst;

	cur_lst = lst;
	while (cur_lst)
	{
		cur_pos = cur_lst->pos;
		while (cur_pos)
		{
			show_shapes(&(cur_pos->shape), base, 1);
			cur_pos = cur_pos->next;
		}
		printf("\n");
		cur_lst = cur_lst->next;
	}
}