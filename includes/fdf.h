/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:28:18 by malaakso          #+#    #+#             */
/*   Updated: 2022/12/18 00:17:16 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

# define COLOR_WHITE 0xffffff
# define COLOR_RED 0xff0000

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_grid;
	int		zoom;
	int		color;
	int		line_offset_x;
	int		line_offset_y;
	float	line_x0;
	float	line_y0;
	float	line_z0;
	float	line_x1;
	float	line_y1;
	float	line_z1;
	float	line_x_step;
	float	line_y_step;
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
void	calculate_steps(t_fdf *fdf);
void	draw(t_fdf *fdf);
void	apply_line_coordinates(t_fdf *fdf);
void	apply_color(t_fdf *fdf);
void	apply_zoom(t_fdf *fdf);
void	apply_transform_isometric(t_fdf *fdf);
void	init_offset(t_fdf *fdf);
void	apply_offset(t_fdf *fdf);
void	clean_exit(int exit_code, t_fdf *fdf);

#endif
