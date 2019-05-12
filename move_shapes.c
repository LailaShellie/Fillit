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

void	move_left(unsigned long int *shape)
{
	int y;

	y = 0;
	while (shape[y] != 0)
	{
		shape[y] >>= 1;
		++y;
	}
}

int		check_y_line(unsigned long int *shape)
{
	unsigned long int	y;
	int					num;

	num = 0;
	y = 0;
	while (y < 32)
	{
		if (shape[y] != 0)
			++num;
		if ((shape[y] & 1) > 0)
			return (1);
		if (num == 3)
			return (0);
		++y;
	}
	return (0);
}

void	move_to_zero(unsigned long int **shape, int num)
{
	t_int a;

	init_struct(&a, 0 ,0);
	while (shape[a.num] == 0)
		++a.num;
	while (a.num < num)
	{
		while (check_y_line(shape[a.num]) == 0)
		{
			move_left(shape[a.num]);
		}
		++a.num;
	}
//	a.num = 0;
//	while (a.num < num)
//	{
//		while (shape[a.num][0] == 0 && a.i < 31)
//		{
//			a.line = a.i;
//			while (shape[a.num][a.line] == 0 && shape[a.num][a.line + 1] != 0 && a.line < 31)
//			{
//
//				a.i = 0;
//				shape[a.num][a.line] ^= shape[a.num][a.line + 1];
//				shape[a.num][a.line + 1] ^= shape[a.num][a.line];
//				++a.line;
//			}
//			++a.i;
//		}
//		++a.num;
//	}
}