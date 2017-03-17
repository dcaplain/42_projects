/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:32:02 by dcaplain          #+#    #+#             */
/*   Updated: 2016/11/11 15:04:27 by dcaplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*tab;
	int		lenght;
	int		i;

	i = 0;
	lenght = max - min;
	if (min < max)
	{
		if ((tab = (int*)malloc(sizeof(*tab) * ((max - min) + 1))))
		{
			while (i < lenght)
			{
				tab[i] = min + i;
				i++;
			}
		}
	}
	else
		return (NULL);
	return (tab);
}
