# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/18 04:34:58 by  iabiesat         #+#    #+#              #
#    Updated: 2026/01/19 12:08:16 by iabiesat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_PATH = minilibx-linux
MLX_LIB = ${MLX_PATH}/libmlx.a
MLX_FLAGS = -L${MLX_PATH} -lmlx -lXext -lX11 -lm

INCLUDE = -I. -I${MLX_PATH}

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

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	make -sC $(MLX_PATH)

$(NAME): $(OBJ) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) ${INCLUDE} -c $< -o $@
	
clean:
	rm -f $(OBJ)
	@make -sC ${MLX_PATH} clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re