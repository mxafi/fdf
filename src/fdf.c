/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:35:48 by malaakso          #+#    #+#             */
/*   Updated: 2022/12/18 00:45:16 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// TODO STUFF
// use mlx images instead of clearing and redrawing
// fix clean exit function and stuffs, leaking 80 bytes
// implement Click on window cross exit
// bonuses?

int	keyboard_event(int key_code, t_fdf *fdf)
{
	if (key_code == 123)
		fdf->line_offset_x -= 15;
	else if (key_code == 124)
		fdf->line_offset_x += 15;
	else if (key_code == 126)
		fdf->line_offset_y -= 15;
	else if (key_code == 125)
		fdf->line_offset_y += 15;
	else if (key_code == 53)
		clean_exit(0, fdf);
	else
		ft_printf("keycode: %i\n", key_code);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw(fdf);
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
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1000, 1000, "FdF");
	mlx_do_key_autorepeaton(fdf->mlx_ptr);
	fdf->zoom = 32;
	init_offset(fdf);
	draw(fdf);
	(void)mlx_key_hook(fdf->win_ptr, keyboard_event, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
