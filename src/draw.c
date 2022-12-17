/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:24:44 by malaakso          #+#    #+#             */
/*   Updated: 2022/12/17 18:20:00 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_fdf *fdf)
{
	float	x_step;
	float	y_step;
	float	max;

	x_step = fdf->end_x - fdf->start_x;
	y_step = fdf->end_y - fdf->start_y;
	max = float_max_2(float_abs(x_step), float_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(fdf->start_x - fdf->end_x) || (int)(fdf->start_y - fdf->end_y))
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, fdf->start_x, fdf->start_y,
			COLOR_WHITE);
		fdf->start_x += x_step;
		fdf->start_y += y_step;
	}
}
