/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_position.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:58:44 by babkar            #+#    #+#             */
/*   Updated: 2023/01/09 09:46:05 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map *update_player_position(t_map *map)
{
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
        map->player.y += sin(map->player.rotation_angle) * map->player.move_speed;
    }
    if (map->player.move_verticaly == S_KEY)
    {
        map->player.x -= cos(map->player.rotation_angle) * map->player.move_speed;
        map->player.y -= sin(map->player.rotation_angle) * map->player.move_speed;
    }
    if (map->player.move_horizontaly == D_KEY)
    {
        map->player.x -= sin(map->player.rotation_angle) * map->player.move_speed;
        map->player.y += cos(map->player.rotation_angle) * map->player.move_speed;
    }
    if (map->player.move_horizontaly == A_KEY)
    {
        map->player.x += sin(map->player.rotation_angle) * map->player.move_speed;
        map->player.y -= cos(map->player.rotation_angle) * map->player.move_speed;
    }
    return (map);
}
