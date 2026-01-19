/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 04:22:05 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/01/19 11:53:04 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define WIDTH		880
#define HEIGHT		620
#define MAX_ITER	300
#define ESC_KEY		65307
#define KEY_UP		65362
#define KEY_DOWN	65364
#define KEY_LEFT	65361
#define KEY_RIGHT	65363
#define MAX_ITER	300
#define KEY_C		99
#define MOUSE_SCROLL_UP	4
#define MOUSE_SCROLL_DOWN	5

typedef struct s_img
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*pex_ptr;
	int		x;
	int		y;
	int		bpp;
	int		endian;
	int		line_len;
	int		fractal_type;
	int		color_schema;
	double	re;
	double	im;
	double	j_re;
	double	j_im;
	double	zoom;
}			t_img;

int		close_window(t_img *img);
int		get_color(int iter, t_img *img);
int		check_input(char *s1, char *s2);
int		handle_key(int keycode, void *param);
int		math_mandelbrot(double z_r, double z_i);
int		math_julia(t_img *img, double z_r, double z_i);
int		handle_mouse(int btn, int x, int y, void *param);
void	render_draw(t_img *img);
double	ft_atof(char *str);
