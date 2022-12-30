/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:03:14 by babkar            #+#    #+#             */
/*   Updated: 2022/12/30 19:20:45 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map player_init(t_map  map)
{
    map.player.rotation_speed = M_PI / 12;
    if (map.player.view == 'N')
        map.player.rotation_angle = 3 * M_PI / 2;
    if (map.player.view == 'S')
        map.player.rotation_angle = M_PI / 2;
    if (map.player.view == 'E')
        map.player.rotation_angle = 2 * M_PI;
    if (map.player.view == 'W')
        map.player.rotation_angle = M_PI;
    map.player.move_speed = 1.0;
    return (map);
}