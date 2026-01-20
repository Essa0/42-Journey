NAME = libftprintf.a

LIBFT = libft/libft.a

OBJ_DIR = obj_file

SRC = ft_printf.c \
putnbr_unsigned_fd.c \
handle_specifier.c \
numlen_base.c \
itoa_base.c \
print_hex_upper_lower.c \
print_int_sign.c \
print_pointer.c \
print_str_chr.c \
print_unsigned.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	@echo "compiling $<"
	@$(CC) $(CFLAGS) -Ilibft -I. -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) libtemp.a
	ar x libtemp.a
	ar rcs $(NAME) $(OBJ) *.o
	rm -f libtemp.a *.o

$(LIBFT):
	make -C libft

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	make -C libft clean
fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re