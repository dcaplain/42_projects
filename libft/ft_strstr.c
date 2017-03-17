/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:10:43 by dcaplain          #+#    #+#             */
/*   Updated: 2016/11/24 15:06:18 by dcaplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*cur_h;
	char	*cur_n;

	cur_h = (char *)haystack;
	cur_n = (char *)needle;
	if (ft_strlen(needle) == 0)
		return (cur_h);
	while (*haystack)
	{
		cur_h = (char *)haystack;
		cur_n = (char *)needle;
		while (*cur_n && *cur_h == *cur_n)
		{
			cur_h++;
			cur_n++;
		}
		if (*cur_n == '\0')
		{
			cur_h = (char *)haystack;
			return (cur_h);
		}
		else
			haystack++;
	}
	return (NULL);
}
