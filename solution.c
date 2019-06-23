/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:04:29 by lshellie          #+#    #+#             */
/*   Updated: 2019/05/21 11:04:31 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

t_positions		*find_pos(t_positions *cur_pos)
{
	while (cur_pos)
	{
		if (cur_pos->status == 0 && cur_pos->used == 0)
			return (cur_pos);
		cur_pos = cur_pos->next;
	}
	return (0);
}

int				find_solution(t_lst *lst)
{
	t_lst		*cur_lst;
	t_positions	*cur_pos;

	if (!lst)
		return (1);
	cur_lst = lst;
	cur_pos = cur_lst->pos;
	cur_pos = find_pos(cur_pos);
	if (!cur_pos)
		return (0);
	cur_pos->active = 1;
	find_traversal(lst, cur_pos, 1);
	if (find_solution(lst->next) == 1)
		return (1);
	else if (find_solution(lst->next) == 0)
	{
		find_traversal(lst, cur_pos, -1);
		clear_used(lst);
		cur_pos->active = 0;
		cur_pos->used = 1;
	}
	return (find_solution(lst));
}

void			make_new_base(unsigned int ***shapes,
		unsigned int *base, unsigned int num)
{
	unsigned int **new_shapes;

	move_to_zero(*shapes, *base, num);
	(*base) += 1;
	new_shapes = allocate(num, *base);
	copy_shapes(new_shapes, *shapes, *base - 1, num);
	delete_shapes(*shapes, num);
	*shapes = new_shapes;
}

int				solution(t_lst **lst, unsigned int ***shapes,
		unsigned int *base, unsigned int num)
{
	t_lst			*new_lst;

	if (find_solution(*lst) != 1)
	{
		make_new_base(shapes, base, num);
		new_lst = make_all_positions(*shapes, *base, num);
		free_lst(lst);
		*lst = new_lst;
		solution(lst, shapes, base, num);
	}
	return (1);
}
