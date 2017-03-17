/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:53:28 by dcaplain          #+#    #+#             */
/*   Updated: 2016/11/29 15:46:32 by dcaplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strtrim(char const *s)
{
	int			start;
	int			end;
	char		*ret;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (s[start] == '\0')
		return (ft_strdup("\0"));
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	if ((ret = ft_strsub(s, start, end - start + 1)))
		return (ret);
	else
		return (NULL);
}
