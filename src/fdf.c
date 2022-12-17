/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:35:48 by malaakso          #+#    #+#             */
/*   Updated: 2022/12/17 20:56:22 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	keyboard_event(int keycode, void *param)
{
	ft_printf("%i", keycode);
	(void)param;
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
	fdf->zoom = 32;
	draw(fdf);
	(void)mlx_key_hook(fdf->win_ptr, keyboard_event, NULL);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
