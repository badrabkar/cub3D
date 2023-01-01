/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:54:44 by babkar            #+#    #+#             */
/*   Updated: 2022/12/31 21:51:58 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    draw_square(t_map map, double i, double j, int color)
{
    for (int k = i * GRID_SIZE; k < (i * GRID_SIZE) + GRID_SIZE; k = k + 1)
        for(int l = j * GRID_SIZE ; l < (j * GRID_SIZE) + GRID_SIZE; l = l + 1)
            my_mlx_pixel_put(&map.img, l, k, color);
}