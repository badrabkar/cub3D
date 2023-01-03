/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:03:14 by babkar            #+#    #+#             */
/*   Updated: 2023/01/02 22:30:43 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map player_init(t_map  map)
{
    if (map.player.view == 'N')
        map.player.rotation_speed = 135;
    if (map.player.view == 'S')
        map.player.rotation_speed = 45;
    if (map.player.view == 'E')
        map.player.rotation_speed = 0;
    if (map.player.view == 'W')
        map.player.rotation_speed = 90;
    map.player.rotation_angle = map.player.rotation_speed * M_PI / 90;
    map.player.move_speed = 0.1 / 2;
    return (map);
}