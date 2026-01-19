/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 03:57:39 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/01/19 03:27:45 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	math_julia(t_img *img, double z_r, double z_i)
{
	int		iter;
	double	real;

	iter = 0;
	while ((z_r * z_r + z_i * z_i) < 4 && iter < MAX_ITER)
	{
		real = z_r * z_r - z_i * z_i + img->j_re;
		z_i = 2 * z_r * z_i + img->j_im;
		z_r = real;
		iter++;
	}
	return (iter);
}
