/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:52:30 by babkar            #+#    #+#             */
/*   Updated: 2022/12/31 15:53:55 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void    draw_line(t_map map, double beginX, double beginY, double endX, double endY, int color)
{
    double deltaX = endX - beginX;
    double deltaY = endY - beginY;

    double steps = fabs(deltaX) > fabs(deltaY) ? fabs(deltaX) : fabs(deltaY);
    double incrementX = deltaX / steps;
    double incrementY = deltaY / steps;

    for (int i = 0; i < steps; i++)
    {
        my_mlx_pixel_put(&map.img, beginX, beginY, color);
        beginX += incrementX;
        beginY += incrementY;
    }
}