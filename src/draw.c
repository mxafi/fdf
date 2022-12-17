/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:24:44 by malaakso          #+#    #+#             */
/*   Updated: 2022/12/17 21:52:54 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_zoom(t_fdf *fdf)
{
	fdf->line_x0 *= fdf->zoom;
	fdf->line_y0 *= fdf->zoom;
	fdf->line_x1 *= fdf->zoom;
	fdf->line_y1 *= fdf->zoom;
}

void	draw_line(t_fdf *fdf)
{
	float	x_step;
	float	y_step;
	int		max;

	fdf->line_x0 = fdf->map_x;
	fdf->line_y0 = fdf->map_y;
	apply_zoom(fdf);
	x_step = fdf->line_x1 - fdf->line_x0;
	y_step = fdf->line_y1 - fdf->line_y0;
	max = float_max_2(int_abs(x_step), int_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(fdf->line_x0 - fdf->line_x1) || (int)(fdf->line_y0 - fdf->line_y1))
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, fdf->line_x0, fdf->line_y0,
			COLOR_WHITE);
		fdf->line_x0 += x_step;
		fdf->line_y0 += y_step;
	}
}

void	draw(t_fdf *fdf)
{
	fdf->map_y = 0;
	while (fdf->map_y < fdf->height)
	{
		fdf->map_x = 0;
		while (fdf->map_x < fdf->width)
		{
			fdf->line_x1 = fdf->map_x + 1;
			fdf->line_y1 = fdf->map_y;
			(void)draw_line(fdf);
			fdf->line_x1 = fdf->map_x;
			fdf->line_y1 = fdf->map_y + 1;
			(void)draw_line(fdf);
			fdf->map_x++;
		}
		fdf->map_y++;
	}
}
