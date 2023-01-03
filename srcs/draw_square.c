/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:54:44 by babkar            #+#    #+#             */
/*   Updated: 2023/01/02 17:00:25 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    draw_square(t_map map, double i, double j, int color)
{
    for (int k = i * GRID_SIZE; k < (i * GRID_SIZE) + map.img.size; k = k + 1)
        for(int l = j * GRID_SIZE ; l < (j * GRID_SIZE) + map.img.size; l = l + 1)
        {
            my_mlx_pixel_put(&map.img, l, k, color);
            // mlx_pixel_put(&map.mlx.mlx, &map.mlx.win, l, k, color);
        }
}