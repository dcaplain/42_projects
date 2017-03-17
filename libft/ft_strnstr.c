/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:53:55 by dcaplain          #+#    #+#             */
/*   Updated: 2016/11/24 15:06:26 by dcaplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	char	*cur_h;
	char	*cur_n;
	char	*limit;

	cur_h = (char *)haystack;
	cur_n = (char *)needle;
	limit = cur_h + n;
	if (ft_strlen(needle) == 0)
		return (cur_h);
	while (*haystack && haystack < limit)
	{
		cur_h = (char *)haystack;
		cur_n = (char *)needle;
		while (*cur_n && *cur_h == *cur_n && cur_h < limit)
		{
			cur_h++;
			cur_n++;
		}
		if (*cur_n == '\0')
			return ((char *)haystack);
		else
			haystack++;
	}
	return (NULL);
}
