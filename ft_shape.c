/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shape.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:39:48 by lshellie          #+#    #+#             */
/*   Updated: 2019/05/07 15:39:52 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

t_shape		**free_shapes(t_shape **shapes)
{
	int i;

	i = 0;
	while (shapes[i] != 0)
	{
		free(shapes[i]);
		shapes[i] = 0;
	}
	free(shapes);
	shapes = 0;
	return (0);
}

void	ft_print_n(char *buf)
{
	int i;

	i = 0;
	while (i < 21)
		ft_putchar(buf[i++]);
}

int 		check_exceptions(char *buf)
{
	t_int	a;

	init_struct(&a, 0, 0);
	while (a.i < 21)
	{
		if ((a.num_of_links = check_slot(buf, a.i, a.i / 4 + 1, '#')) == 2 && buf[a.i] == '.')
			return (1);
		a.num = a.num_of_links;
		++a.i;
		if (a.num == 1 && (a.num_of_links = check_slot(buf, a.i, a.i / 4 + 1, '#')) == 2 && buf[a.i] == '.')
			return (2);
		a.num = 0;
		if (buf[a.i] == '#')
			return (0);
	}
	return (0);
}

void		get_params(t_shape *shape, char *buf)
{
	t_int	a;

	init_struct(&a, 0, 0);
	a.link = check_exceptions(buf);
	while (a.num < 4)
	{
		if (buf[a.i] == '\n')
			++a.i;
		if (a.line != 0)
			++a.line;
		if (buf[a.i++] == '#')
		{
			++a.num;
			if (!a.line)
				++a.line;
			(shape->x)[a.len] = a.line + a.link;
			++a.len;
		}
	}
	shape->base = 4;
	shape->last = 1;
}

t_shape		**make_shapes(int num, char *buf)
{
	t_shape		**shapes;
	t_int		a;

	init_struct(&a, 0, 0);
	if (!num)
		return (0);
	if (!(shapes = (t_shape **)calloc((num + 1), sizeof(shapes))))
		return (0);
	shapes[num] = 0;
	printf("!!!!!!!!!!\n");
	while (a.i < num)
	{
		ft_print_n(buf);
		printf("%d\n", a.i);
		if (!(shapes[a.i] = (t_shape *)calloc(1, sizeof(shapes[a.i]))))
			return (0);
		get_params(shapes[a.i], buf);
		buf += 21;
		++a.i;
	}
	return (shapes);
}