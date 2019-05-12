/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:40:38 by lshellie          #+#    #+#             */
/*   Updated: 2019/05/02 18:40:40 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int		check_slot(const char *buf, int i, int line, char c)
{
	int num;

	num = 0;
	if (line != 1)
		buf[i - 5] == c ? num += 1 : num * 1;
	if (line != 4)
		buf[i + 5] == c ? num += 1 : num * 1;
	if (i != 0)
		buf[i - 1] == c ? num += 1 : num * 1;
	buf[i + 1] == c ? num += 1 : num * 1;
	if (num == 0)
		return (0);
	return (num);
}

int		check_form(const char *buf)
{
	t_int	a;

	init_struct(&a, 1, -1);
	while (buf[++a.i] != 0)
	{
		if (buf[a.i] == '#' && ++a.num)
		{
			if (((a.link) = check_slot(buf, a.i, a.line, '#')) == 0)
				return (-1);
			a.num_of_links += a.link;
		}
		if (buf[a.i] == '\n' && a.line == 5)
			break ;
		if (buf[a.i] == '\n')
			++a.line;
	}
	if (buf[a.i] == '\n' && a.num == 4 && (a.num_of_links == 5
	|| a.num_of_links == 6 || a.num_of_links == 8))
		return (check_form(&buf[a.i + 1]));
	if (buf[a.i] == 0 && a.num == 4 && (a.num_of_links == 5
	|| a.num_of_links == 6 || a.num_of_links == 8))
		return (0);
	return (-1);
}

int		check_file(const char *buf)
{
	t_int	a;

	init_struct(&a, 1, 0);
	while (buf[a.i] != 0)
	{
		if (buf[a.i] == '#' || buf[a.i] == '.' || buf[a.i] == '\n')
		{
			if (buf[a.i] == '\n' && ++a.line)
				if (a.i % 10 != 4 && a.i % 10 != 9)
					return (-1);
			++a.i;
			if (a.i % 10 == 0 && a.line == 5 && buf[a.i] == '\0')
				return (0);
			else if (a.i % 10 == 0 && a.line == 5
			&& buf[a.i] == '\n')
				return (check_file(&buf[a.i + 1]));
			else if (a.i % 10 == 0 && a.line == 5
			&& buf[a.i] != '\n' && buf[a.i] != '\0')
				return (-1);
		}
		else
			return (-1);
	}
	return (-1);
}

int 	num_of_shapes(const char *buf)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (buf[i] != 0)
	{
		if (buf[i] == '#')
			++num;
		++i;
	}
	return (num / 4);
}

int		read_file(const int fd, char **buf)
{
	if (read(fd, *buf, BUFF_SIZE) == -1)
		return (-1);
	if (check_file(*buf) == -1)
	{
		printf("!Invalid file!\n");
		return (-1);
	}
	if (check_form(*buf) == -1)
	{
		printf("!!Invalid shape!!\n");
		return (-1);
	}
	return (num_of_shapes(*buf));
}
