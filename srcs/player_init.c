/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:03:14 by babkar            #+#    #+#             */
/*   Updated: 2022/12/28 22:30:31 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map player_init(t_map  map)
{
    map.player.x = 0;
    map.player.y = 0;
    map.player.turn = 0;
    map.player.walk = 0;
    map.player.rotation_angle = M_PI / 2;
    map.player.rotation_speed = 8 * (M_PI / 180);
    map.player.move_speed = 1.0;
    return (map);
}