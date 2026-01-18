# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/18 04:34:58 by  iabiesat         #+#    #+#              #
#    Updated: 2026/01/18 13:06:54 by  iabiesat        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc

CFLAGS = -Wall -Wextra -Werror

src = main.c \
	render_function/math_julia.c \
	render_function/math_mandelbrot.c \
	render_function/render_draw.c \
	handler_event/handle_key.c \
	handler_event/handle_mouse.c \
	handler_event/get_color.c \
	handler_event/close_window.c \
	helper_function/atof.c \
	helper_function/check_input.c

OBJ = $(src:.c=.o)

all: $(NAME)

MLX_FLAGS = -Iminilibx-linux -Lminilibx-linux -lmlx -lXext -lX11 -lm

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re