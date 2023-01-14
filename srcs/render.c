/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:06:07 by babkar            #+#    #+#             */
/*   Updated: 2023/01/13 23:50:38 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void    render_walls(t_map *map)
// {
//     double  distance_from_player_to_plane;
//     double  wall_height;
//     double  projected_wall_height;
//     double  distance_to_wall;

//     distance_to_wall = distance_between_two_points(map->player.x, map->player.y, map->ray.end_x, map->ray.end_y);
//     wall_height = GRID_SIZE;
//     distance_from_player_to_plane = (WINDOW_WIDTH / 2) / tan(map->player.field_of_view / 2);
//     projected_wall_height = (wall_height / distance_to_wall ) * distance_from_player_to_plane;
// }

int render(t_map *map)
{
    if (map->img.img)
        mlx_destroy_image(map->mlx.mlx, map->img.img);
    mlx_clear_window(map->mlx.mlx, map->mlx.win);
    map->img.img = mlx_new_image(map->mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bits_per_pixel, &map->img.line_length, &map->img.endian);
    
    map = render_mini_map(map);
    map = casting_rays(map);
    mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->img.img, 0, 0);
    return (0);
}