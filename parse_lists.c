/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:14:26 by lshellie          #+#    #+#             */
/*   Updated: 2019/05/20 15:14:27 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void		clear_used(t_lst *lst)
{
	t_lst			*cur_lst;
	t_positions		*cur_pos;

	cur_lst = lst;
	cur_lst = cur_lst->next;
	while (cur_lst)
	{
		cur_pos = cur_lst->pos;
		while (cur_pos)
		{
			if (cur_pos->used == 1)
				cur_pos->used = 0;
			cur_pos = cur_pos->next;
		}
		cur_lst = cur_lst->next;
	}
}

void 		find_traversal(t_lst *lst,t_positions *pos, unsigned int n)
{
	t_lst			*cur_lst;
	t_positions		*cur_pos;

	cur_lst = lst;
	cur_lst = cur_lst->next;
	while (cur_lst)
	{
		cur_pos = cur_lst->pos;
		while (cur_pos)
		{
			if (check_traversal(cur_pos->shape, pos->shape, pos->base))
				cur_pos->status += n;
			cur_pos = cur_pos->next;
		}
		cur_lst = cur_lst->next;
	}
}