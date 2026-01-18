/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 04:04:37 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/01/18 13:45:36 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	error_msg(void)
{
	write(1, "Error", 5);
}

static void	init_img(t_img *img)
{
	img->zoom = 1.0;
	img->re = -0.5;
	img->im = 0.0;
	img->color_schema = 0;
	img->img_ptr = mlx_new_image(img->mlx_ptr, WIDTH, HEIGHT);
	img->pex_ptr = mlx_get_data_addr(img->img_ptr, &img->bpp,
			&img->line_len, &img->endian);
}

static void	init_hooks(t_img *img)
{
	mlx_hook(img->win_ptr, 2, 1L << 0, handle_key, img);
	mlx_hook(img->win_ptr, 4, 1L << 2, handle_mouse, img);
	mlx_hook(img->win_ptr, 17, 0, close_window, img);
}

int	main(int ac, char **av)
{
	t_img	img;

	if ((ac == 2 && check_input(av[1], "mandelbrot") == 0)
		|| (ac == 4 && check_input(av[1], "julia") == 0))
	{
		img.mlx_ptr = mlx_init();
		img.win_ptr = mlx_new_window(img.mlx_ptr, WIDTH, HEIGHT, "fract-ol");
		if (ac == 2)
			img.fractal_type = 0;
		else
		{
			img.fractal_type = 1;
			img.j_re = ft_atof(av[2]);
			img.j_im = ft_atof(av[3]);
		}
		init_img(&img);
		render_draw(&img);
		init_hooks(&img);
		mlx_loop(img.mlx_ptr);
	}
	else
		error_msg();
	return (0);
}
