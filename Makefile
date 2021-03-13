PROJECT_NAME=printf
TEST_NAME=test
CC=clang
CFLAGS=-Wall -Wextra -ggdb3 -fsanitize=address  -fsanitize=leak -fsanitize=signed-integer-overflow

TEST_INC_PATH=-I./lib

USER_INC_PATH=-I../$(PROJECT_NAME)
USER_LDFLAGS=-L../$(PROJECT_NAME) -lftprintf -L../$(PROJECT_NAME)/libft -lft

TEST_FILES=            \
	src/test_int.c     \
	src/test_char.c    \
	src/test_str.c     \
	src/test_ptr.c     \
	src/test_hex.c     \
	src/test_percent.c \
	src/test.c         \
	src/main.c

all: $(TEST_NAME)

$(TEST_NAME): printf

clean:
	$(MAKE) clean -C ../$(PROJECT_NAME)
	rm -f $(TEST_NAME)
	rm -f ./tests/results/log.txt

re: fclean all

fclean: clean
	$(MAKE) fclean -C ../$(PROJECT_NAME)

test: $(NAME)
	$(CC) -ggdb3 $(USER_INC_PATH) $(TEST_INC_PATH) $(TEST_FILES) $(USER_LDFLAGS) -o $(TEST_NAME)

printf:
	$(MAKE) -C ../$(PROJECT_NAME)

.PHONY: all clean fclean re test printf
