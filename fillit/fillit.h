/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthach <nthach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:17:25 by dcaplain          #+#    #+#             */
/*   Updated: 2016/12/12 12:57:01 by dcaplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

# define BUFF_SIZE 545

typedef struct		s_shape
{
	int		x;
	int		y;
	int		size;
}					t_shape;

int					verif(char *input);
void				tab_init(char tab[21][22]);
void				print_tab(char tab[21][22], int size);
void				fillit(char *buf, char tab[21][22]);
int					size_min(char *buf);
int					fill(char *buf, char tab[21][22], t_shape shape, int i);
t_shape				shape_change(t_shape shape, int x, int y, int size);

#endif
