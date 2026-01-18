/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 03:57:44 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/01/18 04:25:09 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	math_mandelbrot(double z_r, double z_i)
{
	double	c_r;
	double	c_i;
	double	temp;
	int		iter;

	c_r = z_r;
	c_i = z_i;
	z_r = 0;
	z_i = 0;
	iter = 0;
	while ((z_r * z_r + z_i * z_i) < 4 && iter < MAX_ITER)
	{
		temp = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_r * z_i + c_i;
		z_r = temp;
		iter++;
	}
	return (iter);
}
