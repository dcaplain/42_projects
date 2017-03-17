.SUFFIXES:
.PHONY: clean, fclean, re

CFLAGS = -Wall -Wextra -Werror
NAME = fillit
SRC = fill.c verif.c main.c more.c
OBJ = fill.o verif.o main.o more.o

all: $(NAME)

$(NAME):
	gcc -c $(SRC) $(FLAG)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
