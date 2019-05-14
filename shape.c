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

void		show_shapes(unsigned int **shapes,
		unsigned int base, unsigned int num)
{
	t_int a;

	init_struct(&a, 0, 0);
	while (a.num < num)
	{
		a.i = 0;
		while (a.i < base)
		{
			ft_putnbr(shapes[a.num][a.i]);
			++a.i;
		}
		ft_putchar('\n');
		++a.num;
	}
}

unsigned int	**copy_shapes(unsigned int **new_base, unsigned int **shapes,
		unsigned int base, unsigned int num)
{
	unsigned int y;
	unsigned int n;

	n = 0;
	while (n < num)
	{
		y = 0;
		while (y < base)
		{
			new_base[n][y] = shapes[n][y];
			++y;
		}
		++n;
	}
	return (new_base);
}

unsigned int	**cut_shapes(unsigned int ***shapes,
		unsigned int base, unsigned int num)
{
	unsigned int	**new_base;

	new_base = allocate(num, base);
	new_base = copy_shapes(new_base, *shapes, base, num);
	delete_shapes(*shapes, num);
	return (new_base);
}

unsigned int	**delete_shapes(unsigned int **shapes, unsigned int num)
{
	unsigned int i;

	i = 0;
	while (i < num)
	{
		free(shapes[i]);
		shapes[i] = 0;
		++i;
	}
	free(shapes);
	shapes = 0;
	return (0);
}

unsigned int	**allocate(unsigned int num, unsigned int base)
{
	t_int			a;
	unsigned int	**shapes;

	init_struct(&a, 0, 0);
	if (!(shapes = (unsigned int **)malloc(num * sizeof(unsigned int *))))
		return (0);
	while (a.i < num)
	{
		if (!(shapes[a.i] = (unsigned int *)malloc(base * sizeof(unsigned int))))
			return (delete_shapes(shapes, num));
		++a.i;
	}
	while (a.num < num)
	{
		a.i = 0;
		while (a.i < base)
		{
			shapes[a.num][a.i] = 0;
			++a.i;
		}
		++a.num;
	}
	return (shapes);
}
