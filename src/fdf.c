/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:35:48 by malaakso          #+#    #+#             */
/*   Updated: 2022/12/15 15:40:09 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int	fd;
	if (argc < 2 || argc > 3)
	{
		ft_printf("Usage : ./fdf <file>.fdf\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (!is_file_descriptor_valid(fd))
	{
		ft_printf("File is not valid.\n");
		close(fd);
		return (1);
	}
	close(fd);
	ft_printf("The height of the map is: %i\n", ret_height(argv[1]));
	return (0);
}
