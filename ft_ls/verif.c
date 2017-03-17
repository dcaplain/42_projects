/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:30:29 by dcaplain          #+#    #+#             */
/*   Updated: 2017/03/11 18:08:49 by dcaplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		v_file(int argc, char **argv)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] != '-' && 1/*check si fichier existant*/)
		{
			ft_putendl("no such file or directory");
			return (0);
		}
		i++;
	}
	return (1);
}

int		v_options(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	j = 1;
	while (argv[i])
	{
		while (argv[i][j] != '\0')
		{
			if (ft_strchr(OPTIONS, argv[i][j]) == NULL && argv[i][0] == '-')
			{
				ft_putendl("option inexistante");
				return (0);
			}
			j++;
		}
		j = 1;
		i++;
	}
	return (1);
}

int		verif(int argc, char **argv)
{
	if (v_options(argc, argv) == 0)
		return (0);
	if (v_file(argc, argv) == 0)
		return (0);
	return (1);
}
