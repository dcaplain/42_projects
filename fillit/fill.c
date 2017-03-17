/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthach <nthach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:49:35 by dcaplain          #+#    #+#             */
/*   Updated: 2016/12/12 12:50:46 by dcaplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		insert(char *buf, char tab[21][22], int index, t_shape shape)
{
	char		alpha;

	alpha = index / 21 + 'A';
	while (index < ((alpha - 'A' + 1) * 21))
	{
		if (buf[index] == '#')
			tab[shape.x + index % 21 / 5][shape.y + index % 21 % 5] = alpha;
		index++;
	}
	return (1);
}

static int		check_insert(char *buf, char tab[21][22], int i, t_shape shape)
{
	char		a;

	a = i / 21 + 'A';
	while (i < ((a - 'A' + 1) * 21))
	{
		if (buf[i] == '#' && shape.x + (i % 21 / 5) >= shape.size && a == 'A')
			return (-1);
		else if (buf[i] == '#' && shape.x + (i % 21 / 5) >= shape.size)
			return (0);
		else if (buf[i] == '#' && (shape.y + i % 21 % 5) >= shape.size)
		{
			shape.y = 0;
			shape.x++;
			i = (a - 'A') * 21;
		}
		else if (buf[i] == '#'
				&& tab[shape.x + i % 21 / 5][shape.y + i % 21 % 5] != '.')
		{
			shape.y++;
			i = (a - 'A') * 21;
		}
		else
			i++;
	}
	return (insert(buf, tab, i - 21, shape));
}

static t_shape	remove_t(char tab[21][22], char alpha, t_shape shape)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	shape.x = 21;
	shape.y = 21;
	while (i <= 21)
	{
		while (j <= 21)
		{
			if (tab[i][j] == alpha)
			{
				if (i < shape.x)
					shape.x = i;
				if (j < shape.y)
					shape.y = j;
				tab[i][j] = '.';
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (shape);
}

static int		replace(char *buf, char tab[21][22], int index, t_shape shape)
{
	char	alpha;
	int		ret;

	alpha = index / 21 + 'A';
	ret = 0;
	shape = remove_t(tab, alpha, shape);
	shape.y++;
	while (ret == 0)
	{
		ret = check_insert(buf, tab, index, shape);
		if (ret == 0)
		{
			ret = replace(buf, tab, index - 21, shape);
			shape.x = 0;
			shape.y = 0;
		}
		if (ret == -1)
			return (-1);
	}
	return (0);
}

int				fill(char *buf, char tab[21][22], t_shape shape, int i)
{
	int			ret;
	t_shape		shape2;

	while (i == 0 || buf[i - 1] != '\0')
	{
		shape = shape_change(shape, 0, 0, -1);
		shape2 = shape;
		ret = 0;
		while (ret == 0)
		{
			ret = check_insert(buf, tab, i, shape);
			if (ret == 0)
				ret = replace(buf, tab, i - 21, shape2);
			shape2.y++;
		}
		if (ret == -1)
		{
			i = 0;
			shape.size++;
			tab_init(tab);
		}
		else if (ret == 1)
			i += 21;
	}
	return (shape.size);
}
