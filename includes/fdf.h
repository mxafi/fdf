/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:28:18 by malaakso          #+#    #+#             */
/*   Updated: 2023/01/13 15:06:08 by malaakso         ###   ########.fr       */
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
# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 1000
# endif
# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 1000
# endif

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_grid;
	int		zoom;
	int		color;
	int		line_offset_x;
	int		line_offset_y;
	int		line_x0;
	int		line_y0;
	int		line_z0;
	int		line_x1;
	int		line_y1;
	int		line_z1;
	int		line_dx;
	int		line_dy;
	int		line_x_step;
	int		line_y_step;
	int		line_error_historical;
	int		line_error_current;
	int		map_x;
	int		map_y;
	void	*mlx_ptr;
	void	*win_ptr;
	int		img_num;
	void	*img1_ptr;
	void	*img2_ptr;
	char	*img1_addr;
	char	*img2_addr;
	int		img_bits_per_pixel;
	int		img_line_length;
	int		img_endian;
}				t_fdf;

int		check_file(char *file_path);
void	read_file(char *file_path, t_fdf *fdf);
void	draw(t_fdf *fdf);
void	draw_flip_image(t_fdf *fdf);
void	img_pixel_put(t_fdf *fdf, int x, int y, int color);
void	init_img(t_fdf *fdf);
void	init_offset(t_fdf *fdf);
void	apply_color(t_fdf *fdf);
void	apply_zoom(t_fdf *fdf);
void	apply_transform_isometric(t_fdf *fdf);
void	apply_offset(t_fdf *fdf);
void	clean_exit(int exit_code, t_fdf *fdf);

#endif
