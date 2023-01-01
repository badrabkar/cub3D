/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mini_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:49:17 by babkar            #+#    #+#             */
/*   Updated: 2023/01/01 13:49:31 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int equal(double a, double b)
{
    return fabs(a - b) < 1e-4;
}

int  render_mini_map(t_map *map)
{
    double old_playerX;
    double old_playerY;

    old_playerX = map->player.x;
    old_playerY = map->player.y;
    map = update_player_position(map);
    if (map->img.img)
        mlx_destroy_image(map->mlx.mlx, map->img.img);
    mlx_clear_window(map->mlx.mlx, map->mlx.win);
    map->img.img = mlx_new_image(map->mlx.mlx, 1920, 1080);
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bits_per_pixel, &map->img.line_length, &map->img.endian);
	my_mlx_pixel_put(&map->img, 5, 5, 0x00FF0000);
    for (int i = 0; i < 14; i++)
    {
        for (int j = 0; map->map[i][j]; j++)
            if (map->map[i][j] == '1')
            {
                for (int k = i * GRID_SIZE; k < (i * GRID_SIZE) + GRID_SIZE; k = k + 1)
                    for(int l = j * GRID_SIZE ; l < (j * GRID_SIZE) + GRID_SIZE; l = l + 1)
                    {
                        my_mlx_pixel_put(&map->img, l, k, 0xff0000);
                    }
            }
    }
    if (map->map[(int)map->player.y][(int)map->player.x] == '1')
    {

        // if (cos(map->player.rotation_angle) > 0 && cos(map->player.rotation_angle) < 1 && !equal(cos(map->player.rotation_angle), 0))
        // {
        //     map->player.x -= sin(map->player.rotation_angle) * map->player.move_speed;
        //     map->player.y = old_playerY;
        //     // if (map->map[(int)map->player.y][(int)map->player.x] == '1')
        //     //         map->player.x = old_playerX;
        // }
        // if (cos(map->player.rotation_angle) < 0 && cos(map->player.rotation_angle) > -1 && !equal(cos(map->player.rotation_angle), 0))
        // {
        //     map->player.x += sin(map->player.rotation_angle) * map->player.move_speed * map->walk_ws;
        //     map->player.y = old_playerY;
        //     if (map->map[(int)map->player.y][(int)map->player.x] == '1')
        //             map->player.x = old_playerX;
        // }
        // else
        // {
            map->player.x = old_playerX;
            map->player.y = old_playerY;
        // }
            
    }
    draw_square(*map, map->player.y, map->player.x, 0x0000ff);
    double x;
    double y;
    x = map->player.x * GRID_SIZE;
    y = map->player.y * GRID_SIZE;
    draw_line(*map,x,y ,x + 32 * cos(map->player.rotation_angle),y + 32 * sin(map->player.rotation_angle),0x00ff00);
    mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->img.img, 0, 0);
    return (0);
}