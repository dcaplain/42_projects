/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:26:18 by dcaplain          #+#    #+#             */
/*   Updated: 2016/11/29 17:56:07 by dcaplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	len;

	len = ft_strlen(s1);
	if (ft_strlen(s2) > len)
		len = ft_strlen(s2);
	return (ft_memcmp(s1, s2, len));
}
