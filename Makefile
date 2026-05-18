##
## EPITECH PROJECT, 2025
## makefile for printf
## File description:
## makefile for printf project 2025 epitech
##

CC	=	epiclang

NAME    =      corewar

UNIT_TEST_BIN =	tests/unit_tests
UNIT_TEST_COV_BIN =	tests/unit_tests_cov
UNIT_TEST_SRC =	tests/unit_tests.c \
			SRC/arena.c \
			SRC/write_in_arena.c \
			lib/my/my_getnbr.c \
			lib/my/my_strcmp.c
UNIT_TEST_COV_FILES = $(addprefix $(UNIT_TEST_COV_BIN)-,$(notdir $(basename $(UNIT_TEST_SRC))))
BRANCH_NAME := $(shell git rev-parse --abbrev-ref HEAD 2>/dev/null || echo detached)
UNIT_TEST_COV_DIR = tests/coverage-$(BRANCH_NAME)

CRITERION_CFLAGS = $(shell pkg-config --cflags criterion)
CRITERION_LIBS = $(shell pkg-config --libs criterion)

MAINTEST        = 	main.c \
				SRC/op.c \
				SRC/my_strncat.c \
				SRC/arena.c \
				SRC/flag_help.c\
				SRC/create_champion.c\
				SRC/write_in_arena.c\
				SRC/dump.c\
				SRC/print_arena.c\
				SRC/loop.c\
				SRC/set_champ_dead.c\
				SRC/check_is_dead.c\
				SRC/instruction.c\
				SRC/scan_map.c\

libflags        =        -L./lib/my/word_array -larray -L./lib/my/open_read -lopendread -L./lib/my/malloc -lmalloc -L./lib/my/linked_list -llinked -L./lib/my/my_printf -lprintf -L./lib/my -lmy -I.

OBJ	=	$(MAINTEST:.c=.o)

TEST_SRC =	tests/test_write_in_arena.c \
			SRC/write_in_arena.c \
			SRC/arena.c \
			lib/my/my_strcmp.c

all: $(NAME)

test: unit_tests functional_tests

coverage: clean
	mkdir -p $(UNIT_TEST_COV_DIR)
	cc -Iinclude -Ilib/my $(CRITERION_CFLAGS) --coverage -o $(UNIT_TEST_COV_BIN) $(UNIT_TEST_SRC) $(CRITERION_LIBS)
	./$(UNIT_TEST_COV_BIN)
	gcov -b $(UNIT_TEST_COV_FILES) >/dev/null
	mv -f *.gcov $(UNIT_TEST_COV_DIR)/
	@echo "Coverage files moved to $(UNIT_TEST_COV_DIR)"

TEST_NAME = tests/unit_tests_exec
TEST_SRC = tests/unit_tests.c
SRC2 = SRC/arena.c SRC/write_in_arena.c lib/my/my_getnbr.c lib/my/my_strcmp.c

do_lib:
	make -C lib/my/

unit_tests: do_lib
	@$(CC) -Iinclude -Ilib/my -o $(TEST_NAME) $(TEST_SRC) $(SRC2) --coverage -lcriterion -lmy -Llib/my

tests_run: unit_tests
	@./$(TEST_NAME)
	@gcovr --gcov-executable "llvm-cov-20 gcov" --exclude tests/

cover: tests_run
	gcovr --gcov-executable "llvm-cov-20 gcov" --exclude tests/ --branches

functional_tests:
	sh tests/functional_tests.sh

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
	$(RM) $(UNIT_TEST_BIN)
	$(RM) $(UNIT_TEST_COV_BIN)
	$(RM) tests/*.gcda tests/*.gcno tests/*.gcov
	$(RM) -r $(UNIT_TEST_COV_DIR)
	$(RM) *.gcda *.gcno

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

.PHONY: test coverage unit_tests functional_tests

