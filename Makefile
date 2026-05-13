##
## EPITECH PROJECT, 2025
## makefile for printf
## File description:
## makefile for printf project 2025 epitech
##

CC	=	epiclang

NAME    =      corewar
TEST_BIN =	tests/test_write_in_arena

MAINTEST        = 	main.c \
				SRC/op.c \
				SRC/my_strncat.c \
				SRC/arena.c \
				SRC/flag_help.c\
				SRC/create_champion.c\
				SRC/write_in_arena.c\
				SRC/loop.c\
				SRC/set_champ_dead.c\
				SRC/check_is_dead.c\

libflags        =        -L./lib/my/word_array -larray -L./lib/my/open_read -lopendread -L./lib/my/malloc -lmalloc -L./lib/my/linked_list -llinked -L./lib/my/my_printf -lprintf -L./lib/my -lmy -I.

OBJ	=	$(MAINTEST:.c=.o)

TEST_SRC =	tests/test_write_in_arena.c \
			SRC/write_in_arena.c \
			SRC/arena.c \
			lib/my/my_strcmp.c

all: $(NAME)

test: $(TEST_BIN)
	./$(TEST_BIN)

$(NAME): $(OBJ)
	make -C ./lib/my/
	make -C ./lib/my/word_array/
	make -C ./lib/my/open_read/
	make -C ./lib/my/malloc/
	make -C ./lib/my/linked_list/
	make -C ./lib/my/my_printf/
	$(CC) -o $(NAME) $(OBJ) $(libflags)

lib : fclean
	make -C ./lib/my/
	make -C ./lib/my/word_array/
	make -C ./lib/my/open_read/
	make -C ./lib/my/malloc/
	make -C ./lib/my/linked_list/
	make -C ./lib/my/my_printf/

valgrind: $(NAME)
	$(RM) *.log
	valgrind --trace-children=yes --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind.log ./$(NAME) G-CPE-200_champions/abel.s

$(TEST_BIN): $(TEST_SRC)
	cc -Iinclude -Ilib/my -o $(TEST_BIN) $(TEST_SRC)

clean:
	make clean -C ./lib/my/
	make clean -C ./lib/my/word_array/
	make clean -C ./lib/my/open_read/
	make clean -C ./lib/my/malloc/
	make clean -C ./lib/my/linked_list/
	make clean -C ./lib/my/my_printf/
	$(RM) $(OBJ)
	$(RM) $(TEST_BIN)
	$(RM) *.gcda *.gcno
	$(RM) *.cor

fclean: clean
	make fclean -C ./lib/my/
	make fclean -C ./lib/my/word_array/
	make fclean -C ./lib/my/open_read/
	make fclean -C ./lib/my/malloc/
	make fclean -C ./lib/my/linked_list/
	make fclean -C ./lib/my/my_printf/
	$(RM) corewar

re: fclean all

NAMETEST	=	units_test
