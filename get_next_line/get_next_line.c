/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:09:38 by dcaplain          #+#    #+#             */
/*   Updated: 2017/03/01 15:12:15 by dcaplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_n(char *buf)
{
	int		i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

void	buf_update(char *buf)
{
	int		i;
	int		j;

	i = 0;
	j = check_n(buf);
	if (buf[j] == '\n')
		j++;
	while (buf[j])
	{
		buf[i] = buf[j];
		i++;
		j++;
	}
	buf[i] = '\0';
}

int		buf0(char **line, char *buf, const int fd)
{
	int		ret;

	ret = 0;
	if (buf[0] == '\0')
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) == 0)
		{
			if (line[0][0] != '\0')
				return (1);
			else
			{
				if (*line)
					free(*line);
				return (0);
			}
		}
		else if (ret == -1)
			return (-1);
		buf[ret] = '\0';
	}
	return (2);
}

int		get_next_line(const int fd, char **line)
{
	int				i;
	int				check;
	size_t			len;
	static char		buf[BUFF_SIZE + 1];

	i = 0;
	if (BUFF_SIZE < 1 || fd < 0 || !line)
		return (-1);
	*line = ft_strnew(BUFF_SIZE + 1);
	while (line[0][i] != '\n')
	{
		check = buf0(line, buf, fd);
		if (check != 2)
			return (check);
		len = ft_strlen(*line) + check_n(buf);
		*line = (char *)ft_realloc(*line, sizeof(char) * len + 1);
		ft_strncat(*line, buf, check_n(buf) + 1);
		line[0][len + 1] = '\0';
		buf_update(buf);
		while (line[0][i] && line[0][i] != '\n')
			i++;
	}
	line[0][i] = '\0';
	return (1);
}
