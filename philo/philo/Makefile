# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: issa <issa@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/26 17:56:44 by  iabiesat         #+#    #+#              #
#    Updated: 2026/05/13 02:42:42 by issa             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

SRCS = main.c init.c routine.c waiter.c utils.c

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

OBJS_DIR = obj

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "create OBJS file...."
	@echo "linking done"

$(OBJS_DIR)/%.o: %.c philo.h
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)
	@echo "remove all OBJS"

fclean: clean
	@rm -f $(NAME)
	@echo "remove all related file"

re: fclean all

.PHONY: all clean fclean re
