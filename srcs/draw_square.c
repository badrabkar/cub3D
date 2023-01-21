/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:54:44 by babkar            #+#    #+#             */
/*   Updated: 2023/01/18 23:41:48 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    draw_square(t_map map, double i, double j, int color)
{
    for (int k = i * 10; k < (i * 10) + map.img.size; k = k + 1)
    {
        for(int l = j * 10 ; l < (j * 10) + map.img.size; l = l + 1)
        {
            my_mlx_pixel_put(&map.img, l, k, color);
        }
    }
}