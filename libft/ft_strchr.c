/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:50:11 by lshellie          #+#    #+#             */
/*   Updated: 2019/04/12 16:54:39 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	sym;
	char	*ptr;
	int		i;

	i = 0;
	ptr = 0;
	sym = c;
	while (1)
	{
		if (s[i] == sym)
		{
			ptr = (char *)(&s[i]);
			return (ptr);
		}
		if (s[i] == '\0' && sym != 0)
			return (0);
		++i;
	}
	return (ptr);
}
