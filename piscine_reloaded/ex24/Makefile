# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaplain <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/11 15:10:05 by dcaplain          #+#    #+#              #
#    Updated: 2016/11/23 11:16:04 by dcaplain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = srcs/ft_putchar.c	\
	  srcs/ft_putstr.c	\
	  srcs/ft_strcmp.c	\
	  srcs/ft_strlen.c	\
	  srcs/ft_swap.c	\

SRCO = ft_putchar.o	\
	   ft_putstr.o 	\
	   ft_strcmp.o	\
	   ft_strlen.o	\
	   ft_swap.o	\

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(FLAG) $(SRC)
	ar rc $(NAME) $(SRCO)
	ranlib $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
