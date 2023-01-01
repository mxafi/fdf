/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:24:48 by malaakso          #+#    #+#             */
/*   Updated: 2023/01/01 17:09:55 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_steps(t_fdf *fdf)
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

void	init_line_error(t_fdf *fdf)
{
	if (fdf->line_dx > fdf->line_dy)
		fdf->line_error_historical = fdf->line_dx / 2;
	else
		fdf->line_error_historical = -fdf->line_dy / 2;
}
