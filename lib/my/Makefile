##
## EPITECH PROJECT, 2025
## makefile for printf
## File description:
## makefile for printf project 2025 epitech
##

CC	=	epiclang

NAME        = libmy.a

RM          = rm -f

SRC    =         my_strlen.c           \
        my_putchar.c           \
        my_strcpy.c            \
        my_put_nbr.c           \
        my_putstr.c            \
        my_revstr.c            \
        my_strlowcase.c \
        my_strncmp.c\
        my_strcmp.c \
        my_int_to_str.c\
        my_getnbr.c\
        my_swap.c\
        my_strndup.c\
        my_strcat.c\
        my_strncpy.c            \
        my_strupcase.c\
        my_puterror.c\

OBJ         = $(SRC:.c=.o)

TEST_NAME   = orga


all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my.h ../../include/

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) units_test
	$(RM) *.gcda *.gcno

re: fclean all
