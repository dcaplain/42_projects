/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthach <nthach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:14:51 by dcaplain          #+#    #+#             */
/*   Updated: 2016/12/16 11:57:50 by dcaplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		tab_init(char tab[21][22])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 21)
	{
		while (j < 21)
		{
			tab[i][j] = '.';
			j++;
		}
		tab[i][j] = '\0';
		j = 0;
		i++;
	}
}

void		print_tab(char tab[21][22], int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
			j++;
		j = 0;
		i++;
	}
	i = 0;
	while (i < size)
	{
		write(1, tab[i], size);
		write(1, "\n", 1);
		i++;
	}
}

int			usage(int argc)
{
	if (argc != 2)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		return (0);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	int			fd;
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		tab[21][22];
	t_shape		shape;

	if (usage(argc) == 0)
		return (0);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		write(1, "error\n", 6);
		return (0);
	}
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	if (verif(buf) == 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	shape.size = size_min(buf);
	tab_init(tab);
	print_tab(tab, fill(buf, tab, shape, 0));
	return (0);
}
