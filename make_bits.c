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
#include "libft/libft.h"

void	set_bits(unsigned int *shape, char *buf)
{
	unsigned int	i;
	unsigned int	x;
	unsigned int	y;

	i = 0;
	x = 0;
	y = 0;
	while (i < 21)
	{
		if (buf[i] == '\n')
		{
			++y;
			x = -1;
		}
		if (buf[i] == '#')
		{
			shape[y] |= (int)1 << x;
		}
		++x;
		++i;
	}
}

void	make_bits(char *buf, unsigned int num)
{
	t_int			a;
	unsigned int	**shapes;
	unsigned int	base;

	base = 4;
	shapes = allocate(num, MAX_BASE);
	init_struct(&a, 0, 0);
	while (a.num < num)
	{
		set_bits(shapes[a.num], buf);
		buf += 21;
		++a.num;
	}
	a.num = 0;
	a.i = 0;
	move_to_zero(shapes, base, num);
	base = make_matrix(&shapes, num);
	show_shapes(shapes, base, num);
	delete_shapes(shapes, num);
}
