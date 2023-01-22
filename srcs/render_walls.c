/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:04:52 by babkar            #+#    #+#             */
/*   Updated: 2023/01/21 23:24:21 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int *get_color_from_texture(t_map *map, double ray_angle)
{

    
    if (map->ray.horizontal_distance < map->ray.vertical_distance)
    {
        if (ray_angle >= M_PI && ray_angle <= 2 * M_PI)
            return (map->north_texture.addr_int);
        else
            return (map->south_texture.addr_int);
    }
    else
    {
        if (cos(ray_angle) > 0)
        {
            return (map->east_texture.addr_int);
        }
        else
            return (map->west_texture.addr_int);
    }
    return (0x000000);
}

void    render_wall(t_map *map, int x, double ray_angle)
{
    double  distance_from_player_to_plane;
    double  projected_wall_height;
    double  distance_to_wall;
    int     texture_x;
    int     *color;
    
    color = get_color_from_texture(map, ray_angle);
    
    if (map->ray.horizontal_distance < map->ray.vertical_distance)
    {
        distance_to_wall = distance_between_two_points(map->player.x, map->player.y, map->ray.horizontal_intersection_x, map->ray.horizontal_intersection_y);
        texture_x = ((int)map->ray.horizontal_intersection_x % GRID_SIZE);
    }
    else
    {
        distance_to_wall = distance_between_two_points(map->player.x, map->player.y, map->ray.vertical_intersection_x, map->ray.vertical_intersection_y);
        texture_x = ((int)map->ray.vertical_intersection_y % GRID_SIZE);
    }
    
    distance_to_wall *= cos(ray_angle - map->player.rotation_angle);
    distance_from_player_to_plane = ((double)(WINDOW_WIDTH) / 2) / tan(map->player.field_of_view / 2);
    projected_wall_height = (GRID_SIZE / distance_to_wall) * distance_from_player_to_plane;
    
    int wall_strip_start =  (WINDOW_HEIGHT / 2) - ((int)projected_wall_height / 2);
    if (wall_strip_start < 0)
        wall_strip_start = 0;
    int wall_strip_end = wall_strip_start +  (int)projected_wall_height;
    
    while (wall_strip_start <= wall_strip_end && wall_strip_start < WINDOW_HEIGHT -1)
    {
        int texture_y = (wall_strip_start + ((int)projected_wall_height / 2) - (WINDOW_HEIGHT / 2)) * ((float)GRID_SIZE / (int)projected_wall_height);
        texture_y *= GRID_SIZE;
        my_mlx_pixel_put(&map->img, x, wall_strip_start, color[texture_y + texture_x]);
        wall_strip_start++;
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
        ray_angle += map->player.field_of_view / map->ray.nbr_rays;
    }
    return (map);
}