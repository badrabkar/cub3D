/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mini_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:49:17 by babkar            #+#    #+#             */
/*   Updated: 2023/01/12 11:47:29 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int equal(double a, double b)
{
    return fabs(a - b) < 1e-4;
}

// void    casting_rays(t_map *map)
// {
//     int fov = 60;
//     double ray_beginX, ray_beginY, ray_endX, ray_endY;



//     ray_beginX = map->player.x;
//     ray_beginY = map->player.y;
    
//     double  deltaDistY, deltaDistX;
//     deltaDistX = sqrt(1 + pow(ray_beginX, 2) / pow(ray_beginY,2)); 
// }

int  render_mini_map(t_map *map)
{
    double old_playerX;
    double old_playerY;
    double x;
    double y;
    old_playerX = map->player.x;
    old_playerY = map->player.y;
    map = update_player_position(map);
    if (map->img.img)
        mlx_destroy_image(map->mlx.mlx, map->img.img);
    mlx_clear_window(map->mlx.mlx, map->mlx.win);
    map->img.img = mlx_new_image(map->mlx.mlx, map->nbr_colums * GRID_SIZE, map->nbr_lines * GRID_SIZE);
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bits_per_pixel, &map->img.line_length, &map->img.endian);
    for (int i = 0; i < map->nbr_lines; i++)
    {
        y = i * GRID_SIZE;
        for (int j = 0; map->map[i][j]; j++)
        {
            if (map->map[i][j] == '1')
            {
                map->img.size = GRID_SIZE;
                draw_square(*map, i, j, 0xffffff);
            }
            if (map->map[i][j] == '0')
            {
                map->img.size = GRID_SIZE;
                draw_square(*map, i,j, 0x000000);
            }
            x = j * GRID_SIZE;
            // draw_line(*map, x, y , x + GRID_SIZE,y , 0x808080);
            // draw_line(*map, x, y , x, y + GRID_SIZE, 0x808080);   
        }
    }
    // draw_line(*map, x + GRID_SIZE, 0 , x + GRID_SIZE, GRID_SIZE * map->nbr_lines, 0x808080);
    // draw_line(*map, 0, y + GRID_SIZE, x + GRID_SIZE, GRID_SIZE + y, 0x808080);   
    if (map->map[(int)map->player.y][(int)old_playerX] == '1' ||  map->map[(int)old_playerY][(int)map->player.x] == '1'|| map->map[(int)map->player.y][(int)map->player.x] == '2')
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
    map->img.size = 10;
    draw_square(*map, map->player.y, map->player.x, 0x0000ff);
    x = map->player.x * GRID_SIZE;
    y = map->player.y * GRID_SIZE;
    draw_line(*map,x,y ,x + 20 * cos(map->player.rotation_angle),y + 20 * sin(map->player.rotation_angle),0x0000ff);
    mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->img.img, 0, 0);
    return (0);
}