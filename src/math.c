/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:24:48 by malaakso          #+#    #+#             */
/*   Updated: 2022/12/17 17:58:47 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	float_max_2(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	float_abs(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}
