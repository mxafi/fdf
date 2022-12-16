/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:29:27 by malaakso          #+#    #+#             */
/*   Updated: 2022/12/16 17:38:16 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_file_descriptor_valid(int fd)
{
	if (fd >= 0 && fd < 1000 && read(fd, NULL, 0) >= 0)
		return (1);
	return (0);
}

int	check_file(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("File is not valid.\n");
		return (0);
	}
	if (!is_file_descriptor_valid(fd))
	{
		ft_printf("File is not valid.\n");
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
