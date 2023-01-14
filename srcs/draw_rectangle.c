/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:32:31 by babkar            #+#    #+#             */
/*   Updated: 2023/01/13 13:47:18 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data  draw_rectangle(t_data img)
{
    for (int i = 0; i < (); i++)
    {
        for (int j = 0; j < WALL_STRIP_WIDTH; j++)
        {
            my_mlx_pixel_put(&img, i, j, 0xff0000);
        }
        
    }
    return (img);
}