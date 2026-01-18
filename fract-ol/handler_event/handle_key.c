/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 03:50:13 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/01/18 04:25:15 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key(int keycode, void *param)
{
	t_img	*img;

	img = (t_img *)param;
	if (keycode == ESC_KEY)
		close_window(img);
	else if (keycode == KEY_RIGHT)
		img->re += (0.1 / img->zoom);
	else if (keycode == KEY_LEFT)
		img->re -= (0.1 / img->zoom);
	else if (keycode == KEY_DOWN)
		img->im += (0.1 / img->zoom);
	else if (keycode == KEY_UP)
		img->im -= (0.1 / img->zoom);
	else if (keycode == KEY_C)
	{
		img->color_schema++;
		if (img->color_schema > 2)
			img->color_schema = 0;
	}
	render_draw(img);
	return (0);
}
