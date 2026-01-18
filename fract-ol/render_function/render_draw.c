/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 03:57:54 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/01/18 04:28:24 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pex_put(t_img *data, int x, int y, int color)
{
	int	offset;

	offset = (y * data->line_len) + (x * (data->bpp / 8));
	*(unsigned int *)(data->pex_ptr + offset) = color;
}

static void	handle_pixel(t_img *img, int x, int y)
{
	double	re;
	double	im;
	int		iter;

	re = (x - WIDTH / 2.0) / (0.5 * WIDTH * img->zoom) + img->re;
	im = (y - HEIGHT / 2.0) / (0.5 * HEIGHT * img->zoom) + img->im;
	if (img->fractal_type == 0)
		iter = math_mandelbrot(re, im);
	else
		iter = math_julia(img, re, im);
	if (iter == MAX_ITER)
		my_pex_put(img, x, y, 0x000000);
	else
		my_pex_put(img, x, y, get_color(iter, img));
}

void	render_draw(t_img *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(img, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
}
