/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 00:56:55 by babkar            #+#    #+#             */
/*   Updated: 2023/01/15 01:20:19 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/cub3D.h"

void	bresenham(t_map map, double x0, double y0, double x1, double y1, double c)
{
	double	dx = fabs(x1 - x0);
	double dy = -fabs(y1 - y0);
	double sx = x0 < x1 ? 1 : -1;
	double sy = y0 < y1 ? 1 : -1;
	double dp1 = dx + dy;
	double dp2 = 0;
	while (1)
	{
		if ((x0 > 0 && x0 < 1920)
			&& (y0 > 0 && y0 < 1080))
			my_mlx_pixel_put(&map.img, x0, y0, c);
		if (x0 == x1 && y0 == y1)
			break ;
		dp2 = 2 * dp1;
		if (dp2 >= dy)
		{
			if (x0 == x1)
				break ;
			dp1 += dy;
			x0 += sx;
		}
		if (dp2 <= dx)
		{
			if (y0 == y1)
				break ;
			dp1 += dx;
			y0 += sy;
		}
	}
}
