/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:18:55 by dcaplain          #+#    #+#             */
/*   Updated: 2017/03/11 17:54:04 by dcaplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	//check format (argc argv ...)
	if (verif(argc, argv) == 0)
		return (0);
	printf("options : %s\n", OPTIONS);
	return (0);
}
