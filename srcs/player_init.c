/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:03:14 by babkar            #+#    #+#             */
/*   Updated: 2023/01/13 19:44:16 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map player_init(t_map  map)
{
    if (map.player.view == 'N')
    {
        map.player.rotation_speed = 135;
        map.ray.ray_angle_speed = 120;
    }
    if (map.player.view == 'S')
    {
        map.player.rotation_speed = 45;
        map.ray.ray_angle_speed = 45;
    }
    if (map.player.view == 'E')
    {
        map.player.rotation_speed = 0;
        map.ray.ray_angle_speed  = 0;
    }
    if (map.player.view == 'W')
    {
        map.player.rotation_speed = 90;
         map.ray.ray_angle_speed  = 90;
    }
    map.player.rotation_angle = map.player.rotation_speed * M_PI / 90;
    map.ray.ray_angle = map.ray.ray_angle_speed * M_PI / 90;
    map.ray.nbr_rays = (WINDOW_WIDTH) / WALL_STRIP_WIDTH;
    map.player.move_speed = 2;
    map.player.move_horizontaly = -1;
    map.player.move_verticaly = -1;
    map.player.rotate = -1;
    map.player.field_of_view = degree_to_radian(60);
    return (map);
}