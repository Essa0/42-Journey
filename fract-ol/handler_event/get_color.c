/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 03:57:29 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/01/19 04:40:41 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iter, t_img *img)
{
	int	r;
	int	g;
	int	b;
	int color;

	if (img->color_schema == 0)
	{
		r = (iter * 5) % 256;
		g = (iter * 2) % 256;
		b = (iter * 10) % 256;
		color = (r << 16 | g << 8 | b);
	}
	else if (img->color_schema == 1)
		color = ((iter * 2522) * (iter < MAX_ITER));
	else
	{
		g = (iter * 15) % 256;
		color = (0 << 16 | g << 8 | 0);
	}
	return (color);
}
