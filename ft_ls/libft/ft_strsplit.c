/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:15:36 by dcaplain          #+#    #+#             */
/*   Updated: 2016/11/29 12:21:29 by dcaplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_words(char const *s, char c)
{
	int		nb;

	nb = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			nb++;
			while (*s != '\0' && *s != c)
				s++;
			s--;
		}
		s++;
	}
	return (nb);
}

static int		ft_wlen(const char *s, char c)
{
	int		len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char		**ft_filltab(char **tab, char *cpy, char c)
{
	int		i;

	i = 0;
	while (*cpy)
	{
		while (*cpy == c)
		{
			*cpy = '\0';
			cpy++;
		}
		if (*cpy != '\0')
		{
			if ((tab[i] = ft_strdup(cpy)))
			{
				tab[i][ft_wlen(cpy, c)] = '\0';
				i++;
			}
			else
				return (NULL);
		}
		while (*cpy && *cpy != c)
			cpy++;
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*cpy;

	if (s)
	{
		if (!(cpy = ft_strdup(s)))
			return (NULL);
		if ((tab = (char **)malloc(sizeof(*tab) * (ft_words(s, c) + 1))))
		{
			if ((tab = ft_filltab(tab, cpy, c)))
			{
				tab[ft_words(s, c)] = NULL;
				free(cpy);
				return (tab);
			}
		}
		free(cpy);
	}
	return (NULL);
}
