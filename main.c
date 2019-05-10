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

void		print(char *s)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (s[i] != 0)
	{
		ft_putchar(s[i]);
		++i;
		++j;
		if (j == 4)
		{
			ft_putchar('\n');
			j = 0;
		}
	}
}

int		main(int argc, char **argv)
{
	char	*buf;
	int 	fd;
	int ret_read;
	t_shape		**shapes;
	int 	i;

	i = -1;
	if (!(buf = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (0);
	if (argc != 2)
	{
		//Display usage
		return (0);
	}
	ft_bzero(buf, BUFF_SIZE);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		//Error message
		return (0);
	}
	if ((ret_read = read_file(fd, &buf)) == -1)
	{
		free(buf);
		buf = 0;
		printf("(%d) - read_file\n", ret_read);
		return (-1);
	}
	printf("(%d) - read_file\n", ret_read);
	shapes = make_shapes(ret_read, buf);
	free_shapes(shapes);
//	convert_shape(shapes, 5);
//	while (shapes != 0)
//	{
//		i = -1;
//		while (++i < 4)
//			printf("-%d", (*shapes)->x[i]);
//		printf("\n");
//		++shapes;
//	}
//	i = -1;
//	while (++i < 4)
//		printf("-%d", (*shapes)->x[i]);
	return  (0);
}