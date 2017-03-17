/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaplain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 10:51:44 by dcaplain          #+#    #+#             */
/*   Updated: 2016/11/12 12:23:01 by dcaplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &(str[i]), 1);
		i++;
	}
}

void	ft_put_error(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(2, &(str[i]), 1);
		i++;
	}
}

int		ft_check_error(int arg)
{
	if (arg == 1)
	{
		ft_put_error("File name missing.\n");
		return (0);
	}
	else if (arg > 2)
	{
		ft_put_error("Too many arguments.\n");
		return (0);
	}
	else if (arg == 2)
		return (1);
	else
		return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	if (ft_check_error(argc) == 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_put_error("open() failed.\n");
			return (0);
		}
		while ((ret = read(fd, buf, BUF_SIZE)))
		{
			buf[ret] = '\0';
			ft_putstr(buf);
		}
		if (close(fd) == -1)
		{
			ft_put_error("close() failed.\n");
			return (0);
		}
	}
	return (0);
}
