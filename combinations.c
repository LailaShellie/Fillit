/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:56:19 by lshellie          #+#    #+#             */
/*   Updated: 2019/05/02 18:56:21 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void		dup_shapes(t_shape **dst, unsigned int *src,
					   unsigned int base)
{
	unsigned int y;

	y = 0;
	while (y < base)
	{
		(*dst)->shapes[y] = src[y];
		++y;
	}
}

void		free_combinations(t_shape **combinations)
{
	t_shape		*cur;
	t_shape		*tmp;

	cur = *combinations;
	while (cur)
	{
		tmp = cur->next;
		free(cur->shapes);
		free(cur);
		cur = cur->next;
		tmp = 0;
	}
	cur = 0;
}

int			move_shape(unsigned int **shape, unsigned int base)
{
	unsigned int x;

	x = 0;
	if ((*shape)[base - 1] != 0 && check_y_line(*shape, base, base) == 1)
		return (1);
	else if (check_y_line(*shape, base, base) == 1 && (*shape)[base - 1] == 0)
	{
		while (x < base)
		{
			move_left(*shape, base);
			++x;
		}
		move_down(*shape, base);
		return (0);
	}
	else if ((*shape)[base - 1] == 0 && check_y_line(*shape, base, base) == 0)
	{
		move_right(*shape, base);
		return (0);
	}
	return (1);
}

t_shape		*new_combination(unsigned int base, char c)
{
	t_shape		*new;

	if (!(new = (t_shape *)ft_memalloc(sizeof(t_shape))))
		return (0);
	new->prev = 0;
	new->next = 0;
	new->base = base;
	if (!(new->shapes = (unsigned int *)malloc(base * sizeof(unsigned int))))
		return (0);
	new->c = c;
	new->status = 0;
	return (new);
}

int		make_combinations(t_shape **combinations,
		unsigned int *shape, unsigned int base, char c)
{
//	t_shape		*new;

	if ((*combinations) == 0)
	{
		(*combinations) = new_combination(base, c);
		dup_shapes((combinations) , shape, base);
		return (1 + make_combinations((combinations) , shape, base, c));
	}
	else if (check_y_line((*combinations)->shapes, base, base) == 0 || (*combinations)->shapes[base - 1] == 0)
	{
		(*combinations)->next = new_combination(base, c);
//		new = (*combinations) ->next;
		((*combinations)->next)->prev = (*combinations) ;
		dup_shapes(&(*combinations)->next, (*combinations)->shapes, base);
		move_shape(&((*combinations)->next->shapes), base);
		return (1 + make_combinations(&((*combinations)->next), ((*combinations)->next)->shapes, base, c));
	}
	return (0);
}