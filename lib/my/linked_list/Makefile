##
## EPITECH PROJECT, 2025
## makefile for printf
## File description:
## makefile for printf project 2025 epitech
##

CC	=	epiclang

NAME        = liblinked.a

RM          = rm -f

SRC    =        linked_list.c\
        len_list.c\
        my_free_list.c\
		push_to_back.c\

OBJ         = $(SRC:.c=.o)

TEST_NAME   = orga


all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) units_test
	$(RM) *.gcda *.gcno

re: fclean all
