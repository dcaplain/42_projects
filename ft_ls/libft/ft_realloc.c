/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 15:54:36 by dcaplain          #+#    #+#             */
/*   Updated: 2016/12/20 09:39:34 by dcaplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_realloc(void *to_realloc, size_t size)
{
	void	*realloc;

	realloc = ft_memalloc(size);
	if (!to_realloc)
		return (realloc);
	realloc = ft_strncpy(realloc, to_realloc, size);
	free(to_realloc);
	to_realloc = NULL;
	return (realloc);
}
