/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 23:18:31 by malaakso          #+#    #+#             */
/*   Updated: 2022/12/17 23:57:48 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_offset(t_fdf *fdf)
{
	fdf->line_offset_x = 410;
	fdf->line_offset_y = 355;
}

void	apply_offset(t_fdf *fdf)
{
	fdf->line_x0 += fdf->line_offset_x;
	fdf->line_y0 += fdf->line_offset_y;
	fdf->line_x1 += fdf->line_offset_x;
	fdf->line_y1 += fdf->line_offset_y;
}
