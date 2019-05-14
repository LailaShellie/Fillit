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

void	move_left(int *shape, int base)
{
	int y;

	y = 0;
	while (y < base)
	{
		shape[y] >>= 1;
		++y;
	}
}

int		check_y_line(int *shape, int base)
{
	int y;

	y = 0;
	while (y < base)
	{
		if ((shape[y] & 1) > 0)
			return (1);
		++y;
	}
	return (0);
}

void	move_to_zero(int **shape, int base, int num)
{
	t_int a;

	init_struct(&a, 0 ,0);
	while (shape[a.num] == 0)
		++a.num;
	while (a.num < num)
	{
		while (check_y_line(shape[a.num], base) == 0)
			move_left(shape[a.num], base);
		++a.num;
	}
	a.num = 0;
	while (a.num < num)
	{
		while (shape[a.num][a.line] == 0)
		{
			while (a.line < base)
			{
				shape[a.num][a.line] ^= shape[a.num][a.line + 1];
				shape[a.num][a.line + 1] ^= shape[a.num][a.line];
				++a.line;
			}
			a.line = 0;
		}
		++a.num;
	}
}