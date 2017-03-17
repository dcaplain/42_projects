/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:30:40 by dcaplain          #+#    #+#             */
/*   Updated: 2016/11/28 15:11:59 by dcaplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if ((sub = (char *)malloc(sizeof(*sub) * (len + 1))))
	{
		while (start--)
			s++;
		ft_strncpy(sub, s, len);
		sub[len] = '\0';
		return (sub);
	}
	return (NULL);
}
