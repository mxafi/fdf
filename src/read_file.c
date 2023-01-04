/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:24:00 by malaakso          #+#    #+#             */
/*   Updated: 2023/01/04 17:02:26 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ret_height(char *file_path)
{
	int		height;
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

static int	ret_width(char *file_path)
{
	int		width;
	int		fd;
	char	**word_grid;
	char	*line;

	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	word_grid = ft_split(line, ' ');
	while (line)
		line = get_next_line(fd);
	width = 0;
	while (word_grid[width])
	{
		width++;
		free(word_grid[width]);
	}
	free(word_grid);
	close(fd);
	return (width);
}

static void	populate_row(int *z_row, char *line)
{
	char	**word_grid;
	int		i;

	word_grid = ft_split(line, ' ');
	i = 0;
	while (word_grid[i])
	{
		z_row[i] = ft_atoi(word_grid[i]);
		free(word_grid[i]);
		i++;
	}
	free(word_grid);
}

static void	populate_grid(char *file_path, t_fdf *fdf)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file_path, O_RDONLY);
	i = 0;
	while (i < fdf->height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		populate_row(fdf->z_grid[i], line);
		i++;
		free(line);
	}
	close(fd);
}

void	read_file(char *file_path, t_fdf *fdf)
{
	int		i;

	fdf->height = ret_height(file_path);
	fdf->width = ret_width(file_path);
	fdf->z_grid = malloc(sizeof(int *) * (fdf->height + 1));
	if (!(fdf->z_grid))
		exit (1);
	i = 0;
	while (i < fdf->height)
		fdf->z_grid[i++] = malloc(sizeof(int *) * (fdf->width + 1));
	populate_grid(file_path, fdf);
}
