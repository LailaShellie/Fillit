/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:01:17 by lshellie          #+#    #+#             */
/*   Updated: 2019/05/06 20:01:19 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void	init_struct(t_int *a, unsigned int line, unsigned int i)
{
	a->i = i;
	a->line = line;
	a->num = 0;
	a->num_of_links = 0;
	a->link = 0;
}

void	init_iter(t_iter *a)
{
	a->i = 0;
	a->x = 0;
	a->num = 0;
	a->y = 0;
	a->j = 0;
}
