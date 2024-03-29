/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:35:48 by malaakso          #+#    #+#             */
/*   Updated: 2023/01/13 15:22:12 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	keyboard_event(int key_code, t_fdf *fdf)
{
	if (key_code == 123)
		fdf->line_offset_x += 15;
	else if (key_code == 124)
		fdf->line_offset_x -= 15;
	else if (key_code == 126)
		fdf->line_offset_y += 15;
	else if (key_code == 125)
		fdf->line_offset_y -= 15;
	else if (key_code == 78)
		fdf->zoom = fdf->zoom / 1.1 - 1;
	else if (key_code == 69)
		fdf->zoom = fdf->zoom * 1.1 + 1;
	else if (key_code == 53)
		clean_exit(0, fdf);
	draw_flip_image(fdf);
	return (0);
}

int	destroy_event(t_fdf *fdf)
{
	clean_exit(0, fdf);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc < 2 || argc > 2)
	{
		write(1, "Usage : ./fdf <file.fdf>\n", 26);
		return (1);
	}
	if (!check_file(argv[1]))
		return (1);
	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (1);
	read_file(argv[1], fdf);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
	fdf->zoom = 32;
	init_offset(fdf);
	init_img(fdf);
	draw_flip_image(fdf);
	mlx_hook(fdf->win_ptr, 02, 0L, keyboard_event, fdf);
	mlx_hook(fdf->win_ptr, 17, 0L, destroy_event, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
