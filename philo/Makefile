NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

SRC = src/philosophers.c \
      src/time.c \
      src/dinner.c \
      src/utils.c \
      src/initializes.c \
      src/main.c \
      src/check.c \
      src/lonely.c 

OBJ = $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

all: $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
