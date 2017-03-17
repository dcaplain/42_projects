/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:08:55 by dcaplain          #+#    #+#             */
/*   Updated: 2016/11/29 14:17:39 by dcaplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_nblen(int nb)
{
	int		len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*ret;
	int		i;

	i = ft_nblen(n) - 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(ret = (char *)malloc(sizeof(*ret) * (ft_nblen(n) + 1))))
		return (NULL);
	ret[i + 1] = '\0';
	if (n == 0)
		ret[i] = '0';
	if (n < 0)
	{
		n = -n;
		ret[0] = '-';
	}
	while (n > 0)
	{
		ret[i] = '0' + (n % 10);
		n = n / 10;
		i--;
	}
	return (ret);
}
