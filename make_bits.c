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

void	set_bits(unsigned long int *shape, char *buf)
{
	unsigned long int i;
	unsigned long int x;
	unsigned long int y;

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
			shape[y] |= (unsigned long int)1 << x;
		}
		++x;
		++i;
	}
}

void	make_bits(char *buf, int num)
{
	t_int				a;
	unsigned long int 	**shapes;
	int 				base;

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
	while (a.num < num)
	{
		a.i = 0;
		while (a.i < base)
		{
			printf("%lu-", shapes[a.num][a.i]);
			++a.i;
		}
		printf("\n");
		++a.num;
	}
	delete_shapes(shapes, num);
}