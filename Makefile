NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=thread

SRC = src/philosophers.c \
		src/better.c \
		src/dinner.c \
		src/utils.c \
		src/initializes.c \
		src/main.c \
		src/check.c \

OBJ = $(SRC:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) $< -o $@

$(NAME):
		$(CC) $(SRC) $(CFLAGS) -o $(NAME)

all: $(NAME)

clean:
		@rm -rf $(OBJ)

fclean: clean
		@rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
