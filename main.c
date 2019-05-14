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

int		main(int argc, char **argv)
{
	char			*buf;
	int				fd;
	int				ret_read;

	ret_read = 0;
	if (!(buf = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (0);
	if (argc != 2)
		return (0);
	ft_bzero(buf, BUFF_SIZE);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (0);
	if ((ret_read = read_file(fd, &buf)) == -1)
	{
		free(buf);
		buf = 0;
		return (-1);
	}
	make_bits(buf, ret_read);
	free(buf);
	buf = 0;
	return (0);
}
