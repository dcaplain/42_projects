/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:10:59 by dcaplain          #+#    #+#             */
/*   Updated: 2016/11/23 10:11:03 by dcaplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	char	*str2;

	str2 = (char *)str;
	while (*str2)
		str2++;
	while (str2 != str && *str2 != c)
		str2--;
	if (*str2 == c)
		return (str2);
	else
		return (NULL);
}
