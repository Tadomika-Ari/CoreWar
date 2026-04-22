##
## EPITECH PROJECT, 2025
## makefile for printf
## File description:
## makefile for printf project 2025 epitech
##

CC	=	epiclang

NAME        = libprintf.a

RM          = rm -f

SRC    =        my_printf.c            \
        flag_c.c            \
        flag_e.c            \
        flag_e_upp.c            \
        flag_f.c            \
        flag_i.c            \
        flag_o.c            \
        flag_percent.c            \
        flag_s.c            \
        flag_u.c            \
        flag_x.c            \
        flag_up_x.c            

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
