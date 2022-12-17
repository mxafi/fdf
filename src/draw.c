/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:24:44 by malaakso          #+#    #+#             */
/*   Updated: 2022/12/17 23:42:13 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_fdf *fdf)
{
	apply_line_coordinates(fdf);
	apply_color(fdf);
	apply_zoom(fdf);
	apply_transform_isometric(fdf);
	apply_offset(fdf);
	calculate_steps(fdf);
	while ((int)(fdf->line_x0 - fdf->line_x1) ||
	(int)(fdf->line_y0 - fdf->line_y1))
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, fdf->line_x0, fdf->line_y0,
			fdf->color);
		fdf->line_x0 += fdf->line_x_step;
		fdf->line_y0 += fdf->line_y_step;
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
			if (fdf->map_x < fdf->width - 1)
				(void)draw_line(fdf);
			fdf->line_x1 = fdf->map_x;
			fdf->line_y1 = fdf->map_y + 1;
			if (fdf->map_y < fdf->height - 1)
				(void)draw_line(fdf);
			fdf->map_x++;
		}
		fdf->map_y++;
	}
}
