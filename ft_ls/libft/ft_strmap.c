/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:13:28 by dcaplain          #+#    #+#             */
/*   Updated: 2016/11/28 14:34:38 by dcaplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*sf;
	size_t	i;

	if (!f || !s)
		return (NULL);
	i = 0;
	sf = ft_strdup(s);
	if (sf == NULL)
		return (NULL);
	while (sf[i])
	{
		sf[i] = f(sf[i]);
		i++;
	}
	return (sf);
}
