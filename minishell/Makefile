NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC = $(shell find src -name "*.c") \
      $(shell find include/linked_list -name "*.c")

OBJ = $(SRC:.c=.o)

INCLUDES = -Iinclude -Iinclude/libft -Iinclude/linked_list

LIBFT_DIR = include/libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -lreadline -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)


clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all