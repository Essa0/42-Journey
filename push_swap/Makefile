# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/07 23:28:37 by  iabiesat         #+#    #+#              #
#    Updated: 2025/12/24 16:08:18 by iabiesat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# project names
NAME = push_swap
LIBRARY = push_swap.a

# libft paths
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# where object files will be store
OBJS_DIR = objs/

# push_swap source files
SRC = split_and_store.c validate_input.c free_full_arr.c ft_atol.c free_partial_arr.c convert_to_integer.c check_for_duplicate.c free_stack.c init_stack.c is_sorted.c min_idx.c max_idx.c ft_strcmp.c s_operation.c p_operation.c r_operation.c rr_operation.c simple_sort.c idx_stack.c sort_algo.c stack_size.c

# main source file
MAIN_SRC = main.c

# compiler
CC = cc

# compiler flags
CFLAGS = -Wall -Wextra -Werror

# include paths
INCLUDES = -I. -I$(LIBFT_DIR)

# command to remove files and directories
RM = rm -rf

# all source files will be compiled into object files in OBJS_DIR
OBJ = $(SRC:%.c=$(OBJS_DIR)%.o)

# default target
all: $(NAME)

# build the executable
$(NAME): $(LIBRARY) $(MAIN_SRC)
	@$(CC) $(CFLAGS) $(INCLUDES) $(MAIN_SRC) $(LIBRARY) $(LIBFT) -o $(NAME)

# build the final static library
$(LIBRARY): $(LIBFT) $(OBJ)
	@cp $(LIBFT) $(LIBRARY)
	@ar rcs $(LIBRARY) $(OBJ)

# compile object files
$(OBJS_DIR)%.o: %.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# build libft if not already built
$(LIBFT):
	@make -C $(LIBFT_DIR)

# clean object files
clean:
	@$(RM) $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean

# clean all generated files
fclean: clean
	@$(RM) $(NAME) $(LIBRARY)
	@make -C $(LIBFT_DIR) fclean

# rebuild the project
re: fclean all

.PHONY: all clean fclean re