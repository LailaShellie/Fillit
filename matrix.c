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

unsigned int	check_x(unsigned int *shapes, unsigned int base)
{
	unsigned int y;

	y = 0;
	while (y < base)
	{
		if (shapes[y] >> base != 0)
			return (1);
		++y;
	}
	return (0);
}

unsigned int	find_base(unsigned int **shapes, unsigned int num)
{
	unsigned int	base;
	unsigned int	n;
	unsigned int	i;

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

unsigned int	make_matrix(unsigned int ***shapes, unsigned int num)
{
	unsigned int	base;

	base = find_base(*shapes, num);
	*shapes = cut_shapes(shapes, base, num);
	return (base);
}
