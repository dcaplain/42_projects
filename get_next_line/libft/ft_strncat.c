/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:12:23 by dcaplain          #+#    #+#             */
/*   Updated: 2016/11/24 13:36:56 by dcaplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*d;

	d = dest;
	while (*dest)
		dest++;
	while (*src && n > 0)
	{
		*(dest++) = *(src++);
		n--;
	}
	*dest = '\0';
	return (d);
}
