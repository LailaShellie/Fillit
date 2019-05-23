/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 21:34:08 by lshellie          #+#    #+#             */
/*   Updated: 2019/05/16 21:34:10 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int				parse_shapes(unsigned int **shapes, unsigned int num)
{
	t_int	a;

	init_struct(&a, 0, 0);
	while (a.num < num)
	{
		if (shapes[a.num][0] == 15)
			++a.line;
		if (shapes[a.num][0] == 1)
		{
			while (a.i < 4 && shapes[a.num][a.i] == 1)
			{
				++a.i;
			}
			if (a.i == 4)
				++a.link;
		}
		++a.num;
	}
	if (a.link > 0 && a.line > 0)
		return (1);
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
		while (shapes[i][base] != 0 || check_x_line(shapes[i], base) != 0)
			++base;
		++i;
	}
	if (base == 4 && parse_shapes(shapes, num))
		return (base + 1);
	return (base);
}

unsigned int	make_matrix(unsigned int ***shapes, unsigned int num)
{
	unsigned int	base;

	base = find_base(*shapes, num);
	*shapes = cut_shapes(shapes, base, num);
	return (base);
}
