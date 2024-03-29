/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_modifiers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:13:37 by malaakso          #+#    #+#             */
/*   Updated: 2023/01/13 15:03:06 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_color(t_fdf *fdf)
{
	if (fdf->line_z0 || fdf->line_z1)
		fdf->color = COLOR_RED;
	else
		fdf->color = COLOR_WHITE;
}

void	apply_zoom(t_fdf *fdf)
{
	if (fdf->zoom < 0)
		fdf->zoom = 0;
	if (fdf->zoom > 1000)
		fdf->zoom = 1000;
	fdf->line_x0 *= fdf->zoom;
	fdf->line_y0 *= fdf->zoom;
	fdf->line_x1 *= fdf->zoom;
	fdf->line_y1 *= fdf->zoom;
}

void	apply_transform_isometric(t_fdf *fdf)
{
	fdf->line_x0 = (fdf->line_x0 - fdf->line_y0) * cos(0.8);
	fdf->line_y0 = (fdf->line_x0 + fdf->line_y0) * sin(0.6) - fdf->line_z0;
	fdf->line_x1 = (fdf->line_x1 - fdf->line_y1) * cos(0.8);
	fdf->line_y1 = (fdf->line_x1 + fdf->line_y1) * sin(0.6) - fdf->line_z1;
}
