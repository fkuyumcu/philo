NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = src/philosophers.c \
		src/better.c \
		src/linguini.c \
		src/utils.c \
		src/initializes.c \
		src/main.c \

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
