/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:29:57 by dcaplain          #+#    #+#             */
/*   Updated: 2017/03/11 17:18:21 by dcaplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	DIR				*rep;
	struct stat		sts;

	if (argc != 2)
		exit(1);
	rep = opendir(argv[1]);
	if (rep == NULL)
	{
		printf("open error\n");
		exit(1);
	}
	printf("Dossier ouvert\n");
	if (stat("./", &sts) != 0)
		exit(1);
	printf("droits : %o\n", sts.st_mode);
	printf("taille : %d\n", (int)sts.st_size);
	if (closedir(rep) == -1)
		exit(-1);
	printf("Dossier ferme\n");
	return (0);
}
