/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:52:30 by babkar            #+#    #+#             */
/*   Updated: 2022/12/26 23:32:24 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"


// void    draw_line(t_map map, int beginX, int beginY, int endX, int endY, int color)
// {
//     int deltaX;
//     int deltaY;
//     float incrementX;
//     float incrementY;
//     float   slope;
//     int     steps;
    
//     deltaX = abs(endX - beginX);
//     deltaY = abs(endY - beginY);
//     steps = deltaX > deltaY ? deltaX : deltaY;
//     slope = (float)deltaX / deltaY;
//     // if (slope < 1)
//     // {
//     //     incrementX = 1;
//     //     incrementY = slope;
//     // }
//     // else if (slope > 1)
//     // {
//     //     incrementX = (float)1 / slope;
//     //     incrementY = 1;
//     // }
//     // else
//     // {
//     //     incrementX = slope;
//     //     incrementY = slope;
//     // }
//     incrementX = (float)deltaX / steps;
//     incrementY = (float)deltaY / steps;
//     for (int i = 0; i < steps; i++)
//     {
//         mlx_pixel_put(map.mlx.mlx, map.mlx.win, beginX, beginY, color);
//         beginX += incrementX;
//         beginY += incrementY;
//     }
// }