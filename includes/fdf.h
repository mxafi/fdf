/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:28:18 by malaakso          #+#    #+#             */
/*   Updated: 2022/12/17 21:54:23 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>

# define COLOR_WHITE 0xffffff
# define COLOR_RED 0xff0000

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_grid;
	int		zoom;
	float	line_x0;
	float	line_y0;
	float	line_x1;
	float	line_y1;
	float	map_x;
	float	map_y;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_fdf;

int		check_file(char *file_path);
void	read_file(char *file_path, t_fdf *fdf);
float	float_max_2(float a, float b);
int		int_max_2(int a, int b);
float	float_abs(float x);
int		int_abs(int x);
void	draw(t_fdf *fdf);

#endif
