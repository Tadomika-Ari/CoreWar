##
## EPITECH PROJECT, 2025
## makefile for printf
## File description:
## makefile for printf project 2025 epitech
##

CC	=	epiclang

NAME        = libarray.a

RM          = rm -f

SRC    =        my_str_to_word_array.c\
		my_free_for_array.c\
		show_array.c\
		array_len.c\

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
