/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:28:18 by malaakso          #+#    #+#             */
/*   Updated: 2022/12/17 17:58:59 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>

typedef struct s_fdf
{
	int	width;
	int	height;
	int	**z_grid;
}				t_fdf;

int		check_file(char *file_path);
void	read_file(char *file_path, t_fdf *fdf);
float	float_max_2(float a, float b);
float	float_abs(float x);

#endif
