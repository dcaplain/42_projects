/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 16:43:24 by dcaplain          #+#    #+#             */
/*   Updated: 2017/03/11 17:15:03 by dcaplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls(void)
{
	DIR					*rep;
	struct dirent		*file;

	rep = opendir("./");
	while ((file = readdir(rep)) != 0)
	{
		if (file->d_name[0] != '.')
			ft_putendl(file->d_name);
	}
}
