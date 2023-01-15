/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:06:07 by babkar            #+#    #+#             */
/*   Updated: 2023/01/15 01:25:21 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int render(t_map *map)
{
    if (map->img.img)
        mlx_destroy_image(map->mlx.mlx, map->img.img);
    mlx_clear_window(map->mlx.mlx, map->mlx.win);
    map->img.img = mlx_new_image(map->mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bits_per_pixel, &map->img.line_length, &map->img.endian);
    
    map = render_walls(map);
    map = render_mini_map(map);
    mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->img.img, 0, 0);
    return (0);
}