/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:26:06 by malaakso          #+#    #+#             */
/*   Updated: 2023/01/04 17:06:37 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_img(t_fdf *fdf)
{
	fdf->img_num = 1;
	fdf->img1_ptr = mlx_new_image(fdf->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	fdf->img2_ptr = mlx_new_image(fdf->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
}

void	img_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > (WINDOW_WIDTH - 1) || y > (WINDOW_HEIGHT - 1))
		return ;
	if (fdf->img_num == 1)
	{
		dst = fdf->img1_addr
			+ (y * fdf->img_line_length + x * (fdf->img_bits_per_pixel / 8));
	}
	else
	{
		dst = fdf->img2_addr
			+ (y * fdf->img_line_length + x * (fdf->img_bits_per_pixel / 8));
	}
	*(unsigned int *)dst = color;
}

static void	flip_1_to_2(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->img2_ptr);
	fdf->img2_ptr = mlx_new_image(fdf->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	fdf->img2_addr = mlx_get_data_addr(fdf->img2_ptr,
			&fdf->img_bits_per_pixel,
			&fdf->img_line_length, &fdf->img_endian);
	fdf->img_num = 2;
}

static void	flip_2_to_1(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->img1_ptr);
	fdf->img1_ptr = mlx_new_image(fdf->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	fdf->img1_addr = mlx_get_data_addr(fdf->img1_ptr,
			&fdf->img_bits_per_pixel,
			&fdf->img_line_length, &fdf->img_endian);
	fdf->img_num = 1;
}

void	draw_flip_image(t_fdf *fdf)
{
	if (fdf->img_num == 1)
		flip_1_to_2(fdf);
	else
		flip_2_to_1(fdf);
	draw(fdf);
	if (fdf->img_num == 1)
	{
		mlx_put_image_to_window(fdf->mlx_ptr,
			fdf->win_ptr, fdf->img1_ptr, 0, 0);
	}
	else
	{
		mlx_put_image_to_window(fdf->mlx_ptr,
			fdf->win_ptr, fdf->img2_ptr, 0, 0);
	}
}
