/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 03:57:12 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/01/18 04:21:49 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_img *img)
{
	mlx_destroy_image(img->mlx_ptr, img->img_ptr);
	mlx_destroy_window(img->mlx_ptr, img->win_ptr);
	mlx_destroy_display(img->mlx_ptr);
	free(img->mlx_ptr);
	exit(0);
	return (0);
}
