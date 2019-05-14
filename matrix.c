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

int 				check_x(int *shapes, int base)
{
	int y;

	y = 0;
	while (y < base)
	{
		if (shapes[y] >> base != 0)
			return (1);
		++y;
	}
	return (0);
}

int 				find_base(int **shapes, int num)
{
	int base;
	int n;
	int i;

	i = 0;
	n = 0;
	base = 0;
	while (base == 0)
	{
		base = ft_sqrt(num * 4 + n);
		++n;
	}
	while (i < num)
	{
		while (shapes[i][base] != 0 || check_x(shapes[i], base) != 0)
			++base;
		++i;
	}

	return (base);
}

int					make_matrix(int ***shapes, int num)
{
	int		base;

	base = find_base(*shapes, num);
	*shapes = cut_shapes(shapes, base, num);
	printf("!%d! - base\n", base);
	return (base);
}