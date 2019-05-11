/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_shape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:53:21 by lshellie          #+#    #+#             */
/*   Updated: 2019/05/08 17:53:23 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void	convert_shape(t_shape **shape, int base, int num)
{
	int 	i;
	int 	j;

	j = 0;
	i = 0;
	while (j < num)
	{
		while (shape[j]->base != base)
		{
			i = -1;
			if (shape[j]->base > base)
				while (++i < 4)
					shape[j]->x[i] = shape[j]->x[i] - shape[j]->x[i] / shape[j]->base;
			else if (shape[j]->base < base)
				while (++i < 4)
					shape[j]->x[i] = shape[j]->x[i] + shape[j]->x[i] / shape[j]->base;
			shape[j]->base > base ? --(shape[j]->base) :
			++(shape[j]->base);
		}
		++j;
	}

}