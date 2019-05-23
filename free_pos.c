/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:26:01 by lshellie          #+#    #+#             */
/*   Updated: 2019/05/20 16:26:03 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void	free_pos_next(t_positions **pos)
{
	t_positions		*cur;
	t_positions		*tmp;

	cur = *pos;
	while (cur)
	{
		tmp = cur->next;
		free(cur->shape);
		free(cur);
		cur = tmp;
		tmp = 0;
	}
	cur = 0;
	*pos = 0;
}

void	free_lst(t_lst **lst)
{
	t_lst *cur;

	while (*lst)
	{
		free_pos_next(&(*lst)->pos);
		cur = *lst;
		free(cur);
		cur = 0;
		*lst = (*lst)->next;
	}
	*lst = 0;
}
