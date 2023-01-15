/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:04:52 by babkar            #+#    #+#             */
/*   Updated: 2023/01/15 03:26:38 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    render_wall(t_map *map, int x, double ray_angle)
{
    double  distance_from_player_to_plane;
    double  wall_height;
    double  projected_wall_height;
    double  distance_to_wall;

    if (map->ray.horizontal_distance < map->ray.vertical_distance)
        distance_to_wall = distance_between_two_points(map->player.x, map->player.y, map->ray.horizontal_intersection_x, map->ray.horizontal_intersection_y);
    else
        distance_to_wall = distance_between_two_points(map->player.x, map->player.y, map->ray.vertical_intersection_x, map->ray.vertical_intersection_y);
        
    distance_to_wall *= cos(ray_angle - map->player.rotation_angle);
    wall_height = GRID_SIZE;
    distance_from_player_to_plane = ((double)(WINDOW_HEIGHT) / 2) / tan(map->player.field_of_view / 2);
    projected_wall_height = (wall_height  / distance_to_wall ) * distance_from_player_to_plane;
    if (projected_wall_height > WINDOW_HEIGHT)
        projected_wall_height = WINDOW_HEIGHT;
    double start = ((double)WINDOW_HEIGHT - projected_wall_height) /2;

    for (int i = start; i < start + projected_wall_height && i < WINDOW_HEIGHT; i = i + 1)
    {
        my_mlx_pixel_put(&map->img, x, i, create_trgb(distance_to_wall, 255, 255, 255));
    } 
}

t_map   *render_walls(t_map *map)
{
    double  ray_angle;

    ray_angle = map->ray.ray_angle;
    
    for (int i = 0; i < map->ray.nbr_rays; i++)
    {
        map = cast_ray(map, ray_angle);
        render_wall(map, i, ray_angle);
        ray_angle += (double)map->player.field_of_view / map->ray.nbr_rays;
    }
    return (map);
}