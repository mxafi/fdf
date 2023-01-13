/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 00:05:40 by malaakso          #+#    #+#             */
/*   Updated: 2023/01/13 15:15:54 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	destroy_z_grid(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->height)
	{
		free(fdf->z_grid[i]);
		i++;
	}
	free(fdf->z_grid);
}

void	clean_exit(int exit_code, t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img1_ptr);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img2_ptr);
	destroy_z_grid(fdf);
	free(fdf);
	exit (exit_code);
}
