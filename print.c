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

void	get_combinations(t_shape *combinations, unsigned int base)
{
	t_shape *cur;
	unsigned int y;

	cur = combinations;
	while (cur)
	{
		y = 0;
		while (y < base)
		{
			ft_putnbr((cur->shapes)[y]);
			ft_putchar('-');
			++y;
		}
		ft_putchar('\n');
		cur = cur->next;
	}
}

int 	show_combinations(t_shape **combinations, unsigned int base, unsigned int num)
{
	t_int a;

	init_struct(&a, 0, 0);
	while (a.num < num)
	{
		get_combinations(combinations[a.num], base);
		++a.num;
	}
	return (num);
}