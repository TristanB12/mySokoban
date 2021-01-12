##
## EPITECH PROJECT, 2019
## C Pool EvalExpr
## File description:
## Project root Makefile
##

CC = gcc

SRC =	src/main.c					\
		src/errors.c				\
		src/tab_functions.c			\
		src/sokoban.c   			\
		src/check_boxes.c 			\
		src/check_storage.c 		\
		src/win_loss_conditions.c	\
		src/check_move.c

OBJ = $(SRC:.c=.o)

CFLAGS = -I./include/ -W -Wall -Wextra  $(DBFLAGS)

LDFLAGS = -L./lib/my -lmy

DBFLAGS = -g -g3 -ggdb

NAME = my_sokoban

all: $(NAME)

$(NAME): libmy $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lncurses $(CFLAGS) $(LDFLAGS)

libmy:
	make -C ./lib/my all

clean:
	rm -f $(OBJ)
	make -C ./lib/my/ clean

fclean: clean
	rm -f $(NAME)
	make -C ./lib/my/ fclean

re: fclean all
