/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:35:48 by malaakso          #+#    #+#             */
/*   Updated: 2022/12/17 16:34:57 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	int i, j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			ft_printf("%i", fdf->z_grid[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	return (0);
}
