/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  iabiesat < iabiesat@student.42amman.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 00:38:25 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/01/18 04:04:01 by  iabiesat        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_mouse(int btn, int x, int y, void *param)
{
	t_img	*img;

	(void)x;
	(void)y;
	img = (t_img *)param;
	if (btn == MOUSE_SCROLL_UP)
		img->zoom *= 1.1;
	else if (btn == MOUSE_SCROLL_DOWN)
		img->zoom *= 0.9;
	render_draw(img);
	return (0);
}
