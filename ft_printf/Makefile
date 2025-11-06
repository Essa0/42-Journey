NAME = libftprintf.a

PRINT_DIR = print_function
HELPER_DIR = helperfunction
PRINTF_DIR = ft_printf
OBJ_DIR = obj_file

SRC = $(PRINTF_DIR)/ft_printf.c \
$(HELPER_DIR)/putnbr_unsigned_fd.c \
$(HELPER_DIR)/ft_strlen.c \
$(HELPER_DIR)/ft_putnbr_fd.c \
$(HELPER_DIR)/ft_putstr_fd.c \
$(HELPER_DIR)/ft_putchar_fd.c \
$(HELPER_DIR)/handle_specifier.c \
$(HELPER_DIR)/numlen_base.c \
$(HELPER_DIR)/itoa_base.c \
$(PRINT_DIR)/print_hex_upper_lower.c \
$(PRINT_DIR)/print_int_sign.c \
$(PRINT_DIR)/print_pointer.c \
$(PRINT_DIR)/print_str_chr.c \
$(PRINT_DIR)/print_unsigned.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	@echo "compiling $<"
	@$(CC) $(CFLAGS) -I. -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
