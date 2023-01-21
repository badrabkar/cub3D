/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:06:07 by babkar            #+#    #+#             */
/*   Updated: 2023/01/19 03:04:58 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    render_floor_and_ceiling(t_map *map)
{
    for (int i = 0; i < WINDOW_HEIGHT / 2; i = i + 1)
    {
        for (int j = 0; j < WINDOW_WIDTH; j++)
        {
            my_mlx_pixel_put(&map->img, j, i, create_trgb(0, map->ceiling.red, map->ceiling.green, map->ceiling.blue));
        }
    }
    for (int i = WINDOW_HEIGHT / 2; i < WINDOW_HEIGHT; i = i + 1)
    {
        for (int j = 0; j < WINDOW_WIDTH; j++)
        {
            my_mlx_pixel_put(&map->img, j, i, create_trgb(0, map->floor.red, map->floor.green, map->floor.blue));
        }
    } 
}

int render(t_map *map)
{
    map = update_player_position(map);
    if (map->img.img)
        mlx_destroy_image(map->mlx.mlx, map->img.img);
    mlx_clear_window(map->mlx.mlx, map->mlx.win);
    map->img.img = mlx_new_image(map->mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bits_per_pixel, &map->img.line_length, &map->img.endian);
	map->img.addr_int = (int *)mlx_get_data_addr(map->img.img, &map->img.bits_per_pixel, &map->img.line_length, &map->img.endian);
    
    render_floor_and_ceiling(map);
    map = render_walls(map);
    // map = render_mini_map(map);
    mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->img.img, 0, 0);
    return (0);
}