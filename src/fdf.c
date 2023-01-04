/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:35:48 by malaakso          #+#    #+#             */
/*   Updated: 2023/01/04 16:54:21 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// TODO STUFF
// fix norm, clean up functions and files
// fix clean exit function and stuffs
// implement Click on window cross exit
// bonuses?

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
	else
		ft_printf("keycode: %i\n", key_code);
	draw_flip_image(fdf);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc < 2 || argc > 2)
	{
		ft_printf("Usage : ./fdf <file>.fdf\n");
		return (1);
	}
	if (!check_file(argv[1]))
		return (1);
	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (1);
	read_file(argv[1], fdf);
	ft_printf("Size: %i by %i\n", fdf->height, fdf->width);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "FdF");
	fdf->zoom = 32;
	init_offset(fdf);
	init_img(fdf);
	draw_flip_image(fdf);
	mlx_hook(fdf->win_ptr, 02, 0L, keyboard_event, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
