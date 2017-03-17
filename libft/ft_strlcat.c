/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:37:18 by dcaplain          #+#    #+#             */
/*   Updated: 2016/11/24 14:48:38 by dcaplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	len;

	d = (char *)(ft_memchr(dest, '\0', n));
	s = (char *)src;
	if (d == NULL)
		return (n + ft_strlen(s));
	len = d - dest;
	while ((size_t)(d - dest) < (n - 1))
	{
		*d = *s;
		d++;
		s++;
	}
	*d = '\0';
	return (len + ft_strlen(src));
}
