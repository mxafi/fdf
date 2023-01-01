/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:26:06 by malaakso          #+#    #+#             */
/*   Updated: 2023/01/01 19:22:27 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_img(t_fdf *fdf)
{
	fdf->img_num = 1;
	fdf->img1_ptr = mlx_new_image(fdf->mlx_ptr, 1000, 1000);
	fdf->img2_ptr = mlx_new_image(fdf->mlx_ptr, 1000, 1000);
}

void	img_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

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

void	draw_flip_image(t_fdf *fdf)
{
	if (fdf->img_num == 1)
	{
		mlx_destroy_image(fdf->mlx_ptr, fdf->img2_ptr);
		fdf->img2_ptr = mlx_new_image(fdf->mlx_ptr, 1000, 1000);
		fdf->img2_addr = mlx_get_data_addr(fdf->img2_ptr,
				&fdf->img_bits_per_pixel,
				&fdf->img_line_length, &fdf->img_endian);
		fdf->img_num = 2;
	}
	else
	{
		mlx_destroy_image(fdf->mlx_ptr, fdf->img1_ptr);
		fdf->img1_ptr = mlx_new_image(fdf->mlx_ptr, 1000, 1000);
		fdf->img1_addr = mlx_get_data_addr(fdf->img1_ptr,
				&fdf->img_bits_per_pixel,
				&fdf->img_line_length, &fdf->img_endian);
		fdf->img_num = 1;
	}
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
