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

void	convert_shape(t_shape **shape, int base)
{
	int 	i;


	while (shape != 0)
	{
		printf("~~~~\n");
		while ((*shape)->base != base)
		{
			i = -1;
			if ((*shape)->base > base)
				while (++i < 4)
					(*shape)->x[i] =(*shape)->x[i] - (*shape)->x[i] / (*shape)->base;
			else if ((*shape)->base < base)
				while (++i < 4)
					(*shape)->x[i] = (*shape)->x[i] - (*shape)->x[i] / (*shape)->base;
			(*shape)->base > base ? --((*shape)->base) :
			++((*shape)->base);
		}
		++shape;
	}

}