/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:24:48 by malaakso          #+#    #+#             */
/*   Updated: 2022/12/17 23:16:25 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	int_max_2(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	int_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	calculate_steps(t_fdf *fdf)
{
	int	max;

	fdf->line_x_step = fdf->line_x1 - fdf->line_x0;
	fdf->line_y_step = fdf->line_y1 - fdf->line_y0;
	max = int_max_2(int_abs(fdf->line_x_step), int_abs(fdf->line_y_step));
	fdf->line_x_step /= max;
	fdf->line_y_step /= max;
}
