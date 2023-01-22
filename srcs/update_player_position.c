/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_position.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:58:44 by babkar            #+#    #+#             */
/*   Updated: 2023/01/22 01:55:03 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_map *update_player_position(t_map *map)
{
    double old_player_x;
    double old_player_y;
    
    old_player_x = map->player.x;
    old_player_y = map->player.y;
    if (map->player.rotate == LEFT_ARROW_KEY)
    {
        map->player.rotation_speed = ((int)map->player.rotation_speed + 1) % 180;
        map->player.rotation_angle = map->player.rotation_speed * M_PI / 90;
        map->ray.ray_angle_speed = ((int)map->ray.ray_angle_speed + 1) % 180;
        map->ray.ray_angle = map->ray.ray_angle_speed * M_PI / 90;
    }   
    if (map->player.rotate == RIGHT_ARROW_KEY)
    {  
        map->player.rotation_speed = ((int)map->player.rotation_speed + 179) % 180;
        map->player.rotation_angle = map->player.rotation_speed * M_PI / 90;
        map->ray.ray_angle_speed = ((int)map->ray.ray_angle_speed + 179) % 180;
        map->ray.ray_angle = map->ray.ray_angle_speed * M_PI / 90;
    } 
    if (map->player.move_verticaly == W_KEY)
    {   
        map->player.x += cos(map->player.rotation_angle) * map->player.move_speed;
        // if (map->map[(int)old_player_y / GRID_SIZE][(int)map->player.x / GRID_SIZE] == '1')
        //     map->player.x = old_player_x;
        map->player.y += sin(map->player.rotation_angle) * map->player.move_speed;
        // if (map->map[(int)map->player.y / GRID_SIZE][(int)old_player_y / GRID_SIZE] == '1')
        //     map->player.y = old_player_y;
    }
    if (map->player.move_verticaly == S_KEY)
    {
        map->player.x -= cos(map->player.rotation_angle) * map->player.move_speed;
        // if (map->map[(int)old_player_y / GRID_SIZE][(int)map->player.x / GRID_SIZE] == '1')
        //     map->player.x = old_player_x;
        map->player.y -= sin(map->player.rotation_angle) * map->player.move_speed;
        // if (map->map[(int)map->player.y / GRID_SIZE][(int)old_player_y / GRID_SIZE] == '1')
        //     map->player.y = old_player_y;
    }
    if (map->player.move_horizontaly == D_KEY)
    {
        map->player.x -= sin(map->player.rotation_angle) * map->player.move_speed;
        // if (map->map[(int)old_player_y / GRID_SIZE][(int)map->player.x / GRID_SIZE] == '1')
        //     map->player.x = old_player_x;
        map->player.y += cos(map->player.rotation_angle) * map->player.move_speed;
        // if (map->map[(int)map->player.y / GRID_SIZE][(int)old_player_y / GRID_SIZE] == '1')
        //     map->player.y = old_player_y;
    }
    if (map->player.move_horizontaly == A_KEY)
    {
        map->player.x += sin(map->player.rotation_angle) * map->player.move_speed;
        // if (map->map[(int)old_player_y / GRID_SIZE][(int)map->player.x / GRID_SIZE] == '1')
        //     map->player.x = old_player_x;
        map->player.y -= cos(map->player.rotation_angle) * map->player.move_speed;
        // if (map->map[(int)map->player.y / GRID_SIZE][(int)old_player_y / GRID_SIZE] == '1')
        //     map->player.y = old_player_y;
    }
    if (map->map[((int)map->player.y + GRID_SIZE / 4) / GRID_SIZE][(int)old_player_x / GRID_SIZE] == '1'
    || map->map[(int)old_player_y / GRID_SIZE][((int)map->player.x + GRID_SIZE / 4) / GRID_SIZE] == '1' 
    || map->map[((int)map->player.y - GRID_SIZE / 4) / GRID_SIZE][(int)old_player_x / GRID_SIZE] == '1'
    || map->map[(int)old_player_y / GRID_SIZE][((int)map->player.x - GRID_SIZE / 4) / GRID_SIZE] == '1' 
    || map->map[((int)map->player.y) / GRID_SIZE][(int)old_player_x / GRID_SIZE] == '1'
    || map->map[(int)old_player_y / GRID_SIZE][((int)map->player.x) / GRID_SIZE] == '1' 
    || map->map[((int)map->player.y + GRID_SIZE / 4) / GRID_SIZE][((int)map->player.x + GRID_SIZE / 4) / GRID_SIZE] == '1'
    || map->map[((int)map->player.y - GRID_SIZE / 4) / GRID_SIZE][((int)map->player.x - GRID_SIZE / 4) / GRID_SIZE] == '1'
    || map->map[((int)map->player.y - GRID_SIZE / 4) / GRID_SIZE][((int)map->player.x + GRID_SIZE / 4) / GRID_SIZE] == '1'
    || map->map[((int)map->player.y + GRID_SIZE / 4) / GRID_SIZE][((int)map->player.x - GRID_SIZE / 4) / GRID_SIZE] == '1'
    || map->map[(int)map->player.y/ GRID_SIZE][(int)map->player.x / GRID_SIZE] == '2')
    {
        map->player.x = old_player_x;
        map->player.y = old_player_y;
    }
    return (map);
}
