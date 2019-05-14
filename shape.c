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

unsigned long int	**copy_shapes(unsigned long int **new_base,
		unsigned long int **shapes, int base, int num)
{
	int y;
	int n;

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

unsigned long int	**cut_shapes(unsigned long int	***shapes, int base, int num)
{
	unsigned long int	**new_base;

	new_base = allocate(num, base);
	new_base = copy_shapes(new_base, *shapes, base, num);
	delete_shapes(*shapes, num);
	return (new_base);
}

int					delete_shapes(unsigned long int **shapes, int num)
{
	int i;

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

unsigned long int	**allocate(int num, int base)
{
	t_int a;
	unsigned long int **shapes;

	init_struct(&a, 0 ,0);
	if (!(shapes = (unsigned long int **)malloc(num * sizeof(unsigned long int *))))
		return (0);
	while (a.i < num)
	{
		if (!(shapes[a.i] = (unsigned long int *)malloc(base * sizeof(unsigned long int))))
		{
			delete_shapes(shapes, num);
			return (0);
		}
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