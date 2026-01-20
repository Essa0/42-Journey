NAME_CLIENT = client
NAME_SERVER = server

CC = cc
CFLAGS = -Wall -Wextra -Werror

PRINTF_DIR = ./ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

SERVER_SRCS = server.c
CLIENT_SRCS = client.c

OBJS_SERVER = $(SERVER_SRCS:.c=.o)
OBJS_CLIENT = $(CLIENT_SRCS:.c=.o)

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(SERVER_SRCS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(SERVER_SRCS) $(PRINTF_LIB) -o $(NAME_SERVER)

$(NAME_CLIENT): $(CLIENT_SRCS) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(CLIENT_SRCS) $(PRINTF_LIB) -o $(NAME_CLIENT)

$(PRINTF_LIB):
	@make -C $(PRINTF_DIR)

clean:
	@rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	@make clean -C $(PRINTF_DIR)

fclean: clean
	@rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@make fclean -C $(PRINTF_DIR)

re: fclean all
.PHONY: all clean fclean re