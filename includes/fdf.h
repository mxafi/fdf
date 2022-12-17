/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:28:18 by malaakso          #+#    #+#             */
/*   Updated: 2022/12/17 18:23:50 by malaakso         ###   ########.fr       */
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
	float	start_x;
	float	start_y;
	float	end_x;
	float	end_y;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_fdf;

int		check_file(char *file_path);
void	read_file(char *file_path, t_fdf *fdf);
float	float_max_2(float a, float b);
float	float_abs(float x);

#endif
