/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 19:14:28 by lshellie          #+#    #+#             */
/*   Updated: 2019/05/21 19:14:31 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void			prepare_print(char *buf,
		unsigned int len, unsigned int base)
{
	unsigned int i;
	unsigned int x;

	x = 0;
	i = 0;
	while (i < len)
	{
		if (x == base)
		{
			buf[i] = '\n';
			x = -1;
		}
		else if (x != base)
			buf[i] = '.';
		++i;
		++x;
	}
	buf[i - 1] = 0;
}

void			set_sym(unsigned int *shape,
		char *buf, char c, unsigned int base)
{
	unsigned int x;
	unsigned int y;
	unsigned int i;

	y = 0;
	i = 0;
	while (y < base && buf[i] != 0)
	{
		x = 0;
		while (x < base)
		{
			if ((shape[y] & (1 << x)) != 0)
			{
				buf[i] = c;
			}
			++x;
			++i;
			if (buf[i] == '\n')
				++i;
		}
		++y;
	}
}

char			get_sym(t_positions *pos,
		char *buf, unsigned int base)
{
	unsigned int i;

	i = 0;
	while (pos)
	{
		if (pos->active)
		{
			set_sym(pos->shape, buf, pos->c, base);
		}
		pos = pos->next;
	}
	return (0);
}

void			show_all(t_lst *lst,
		unsigned int base)
{
	unsigned int	len;
	char			*buf;

	len = base * (base + 1) + 1;
	if (!(buf = (char *)ft_memalloc(len)))
		return ;
	prepare_print(buf, len, base);
	while (lst)
	{
		get_sym(lst->pos, buf, base);
		lst = lst->next;
	}
	ft_putstr(buf);
}
