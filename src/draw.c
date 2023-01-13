/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:24:44 by malaakso          #+#    #+#             */
/*   Updated: 2023/01/13 15:03:18 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_line_coordinates(t_fdf *fdf)
{
	fdf->line_x0 = fdf->map_x;
	fdf->line_y0 = fdf->map_y;
	fdf->line_z0 = fdf->z_grid[(int)fdf->line_y0][(int)fdf->line_x0];
	fdf->line_z1 = fdf->z_grid[(int)fdf->line_y1][(int)fdf->line_x1];
}

static void	init_line_error(t_fdf *fdf)
{
	if (fdf->line_dx > fdf->line_dy)
		fdf->line_error_historical = fdf->line_dx / 2;
	else
		fdf->line_error_historical = -fdf->line_dy / 2;
}

static void	calculate_steps(t_fdf *fdf)
{
	fdf->line_dx = abs(fdf->line_x1 - fdf->line_x0);
	fdf->line_dy = abs(fdf->line_y1 - fdf->line_y0);
	if (fdf->line_x0 < fdf->line_x1)
		fdf->line_x_step = 1;
	else
		fdf->line_x_step = -1;
	if (fdf->line_y0 < fdf->line_y1)
		fdf->line_y_step = 1;
	else
		fdf->line_y_step = -1;
}

static void	draw_line_bresenham(t_fdf *fdf)
{
	apply_line_coordinates(fdf);
	apply_color(fdf);
	apply_zoom(fdf);
	apply_transform_isometric(fdf);
	apply_offset(fdf);
	calculate_steps(fdf);
	init_line_error(fdf);
	while (1)
	{
		img_pixel_put(fdf, fdf->line_x0, fdf->line_y0,
			fdf->color);
		if (fdf->line_x0 == fdf->line_x1 && fdf->line_y0 == fdf->line_y1)
			break ;
		fdf->line_error_current = fdf->line_error_historical;
		if (fdf->line_error_current > -fdf->line_dx)
		{
			fdf->line_error_historical -= fdf->line_dy;
			fdf->line_x0 += fdf->line_x_step;
		}
		if (fdf->line_error_current < fdf->line_dy)
		{
			fdf->line_error_historical += fdf->line_dx;
			fdf->line_y0 += fdf->line_y_step;
		}
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
				draw_line_bresenham(fdf);
			fdf->line_x1 = fdf->map_x;
			fdf->line_y1 = fdf->map_y + 1;
			if (fdf->map_y < fdf->height - 1)
				draw_line_bresenham(fdf);
			fdf->map_x++;
		}
		fdf->map_y++;
	}
}
