/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthach <nthach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:44:32 by dcaplain          #+#    #+#             */
/*   Updated: 2016/12/12 12:57:15 by dcaplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		format_verif(char *t)
{
	int		lines;
	int		columns;

	lines = 0;
	while (lines <= 3)
	{
		columns = 0;
		while (columns <= 3)
		{
			if (*t != '.' && *t != '#')
				return (0);
			columns++;
			t++;
		}
		if (*t != '\n')
			return (0);
		lines++;
		t++;
	}
	if (*t == '\0')
		return (2);
	else if (*t == '\n')
		return (1);
	else
		return (0);
}

static int		tetri_verif(char *t)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (t[i] && i <= 20)
	{
		if (t[i] == '#')
		{
			size++;
			if (!(((t[i + 1] == '#' && (t[i + 2] == '#' || t[i + 5] == '#'
				|| t[i + 6] == '#')) || (t[i + 5] == '#' && (t[i + 10] == '#'
				|| t[i + 6] == '#' || t[i + 4] == '#')))) && (size == 1))
				return (0);
			if (!((i >= 1 && t[i - 1] == '#') || (i <= 17 && t[i + 1] == '#')
					|| (i >= 5 && t[i - 5] == '#')
					|| (i <= 14 && t[i + 5] == '#')))
				return (0);
		}
		i++;
	}
	if (size == 4)
		return (1);
	else
		return (0);
}

static void		adjust_height(char *t)
{
	int		i;

	i = 0;
	while (t[0] == '.' && t[1] == '.' && t[2] == '.' && t[3] == '.')
	{
		while (i <= 14)
		{
			t[i] = t[i + 5];
			if (t[i] != '\n' && t[i + 5] != '\n')
				t[i + 5] = '.';
			i++;
		}
		i = 0;
	}
}

static void		adjust_length(char *t)
{
	int		i;

	i = 0;
	while (t[0] == '.' && t[5] == '.' && t[10] == '.' && t[15] == '.')
	{
		while (i <= 18)
		{
			if (t[i] != '\n' && t[i + 1] != '\n')
			{
				t[i] = t[i + 1];
				t[i + 1] = '.';
			}
			i++;
		}
		i = 0;
	}
}

int				verif(char *input)
{
	int		i;

	i = 0;
	if (!input)
		return (0);
	while (format_verif(&(input[i])) == 1 && tetri_verif(&(input[i])) == 1)
	{
		adjust_height(&(input[i]));
		adjust_length(&(input[i]));
		i += 21;
	}
	if (format_verif(&(input[i])) == 2 && tetri_verif(&(input[i])) == 1)
	{
		adjust_height(&(input[i]));
		adjust_length(&(input[i]));
		return (1);
	}
	else
		return (0);
}
