/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 14:54:57 by lshellie          #+#    #+#             */
/*   Updated: 2019/05/19 15:00:02 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int 		check_traversal(unsigned int *shape,
						   unsigned int *shp, unsigned int base)
{
	unsigned int	y;

	y = 0;
	while (y < base)
	{
		if ((shape[y] & shp[y]) > 0)
			return (1);
		++y;
	}
	return (0);
}

unsigned int	check_y_line(const unsigned int *shape, unsigned int base, unsigned int x)
{
	unsigned int y;

	y = 0;
	while (y < base)
	{
		if (((shape[y] & (1 << (x - 1))) > 0))
			return (1);
		++y;
	}
	return (0);
}

unsigned int	check_x_line(unsigned int *shapes, unsigned int base)
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
