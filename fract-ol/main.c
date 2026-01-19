/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 04:04:37 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/01/19 12:03:41 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

static int	is_valid_double(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] == '.')
		{
			count++;
			if (count > 1)
				return (0);
		}
		else if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	parse_args(int ac, char **av, t_img *img)
{
	if (ac == 2 && !check_input(av[1], "mandelbrot"))
	{
		img->fractal_type = 0;
		return (1);
	}
	if (ac == 4 && !check_input(av[1], "julia"))
	{
		if (is_valid_double(av[2]) && is_valid_double(av[3]))
		{
			img->fractal_type = 1;
			img->j_re = ft_atof(av[2]);
			img->j_im = ft_atof(av[3]);
			return (1);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_img	img;

	if (parse_args(ac, av, &img))
	{
		img.mlx_ptr = mlx_init();
		img.win_ptr = mlx_new_window(img.mlx_ptr, WIDTH, HEIGHT, "fract-ol");
		init_img(&img);
		render_draw(&img);
		init_hooks(&img);
		mlx_loop(img.mlx_ptr);
	}
	else
	{
		write(2, "Error: Invalid input\n", 25);
		write(1, "\nUsage:\n", 8);
		write(1, "\t./fractol mandelbrot\n", 22);
		write(1, "\t./fractol julia <re> <im>\n", 27);
		write(1, "\nExample:\n", 11);
		write(1, "\t./fractol julia -0.4 0.6\n", 26);
		return (1);
	}
	return (0);
}
