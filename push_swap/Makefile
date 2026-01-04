# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/07 23:28:37 by  iabiesat         #+#    #+#              #
#    Updated: 2025/12/25 01:28:53 by  iabiesat        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

LIBFT = ./libft/libft.a

OBJS_DIR = objs/

SRCS = check_for_duplicate.c\
main.c\
convert_to_integer.c\
free_full_arr.c\
free_partial_arr.c\
free_stack.c\
ft_atol.c\
ft_strcmp.c\
idx_stack.c\
init_stack.c\
is_sorted.c\
max_idx.c\
min_idx.c\
p_operation.c\
r_operation.c\
rr_operation.c\
s_operation.c\
simple_sort.c\
sort_algo.c\
split_and_store.c\
stack_size.c\
validate_input.c

OBJS = $(SRCS:%.c=${OBJS_DIR}%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C ./libft

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re