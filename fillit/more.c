/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:11:22 by dcaplain          #+#    #+#             */
/*   Updated: 2016/12/12 12:39:40 by dcaplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			size_min(char *buf)
{
	int			nb;
	int			size;

	nb = 0;
	size = 0;
	while (*buf)
	{
		if (*buf == '#')
			nb++;
		buf++;
	}
	while (size * size < nb)
		size++;
	return (size);
}

t_shape		shape_change(t_shape shape, int x, int y, int size)
{
	if (x != -1)
		shape.x = x;
	if (y != -1)
		shape.y = x;
	if (size != -1)
		shape.size = x;
	return (shape);
}
