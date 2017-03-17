/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:12:43 by dcaplain          #+#    #+#             */
/*   Updated: 2016/11/29 14:05:09 by dcaplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*cpy;

	if ((cpy = (char *)malloc(sizeof(*cpy) * (ft_strlen(str) + 1))))
	{
		ft_strcpy(cpy, str);
		return (cpy);
	}
	else
		return (NULL);
}
