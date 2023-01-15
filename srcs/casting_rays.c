/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:08:13 by babkar            #+#    #+#             */
/*   Updated: 2023/01/15 02:05:10 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_map   *vertical_intersection(t_map *map, double ray_angle)
{
    double  x_steps;
    double  y_steps;

    x_steps = GRID_SIZE;
    map->ray.begin_x = floor(map->player.x / GRID_SIZE) * GRID_SIZE;
    if (cos(ray_angle) < 0)
    {
        x_steps *= -1;
    } 
    else
        map->ray.begin_x += GRID_SIZE;
    map->ray.begin_y = map->player.y + (map->ray.begin_x - map->player.x) * tan(ray_angle);
    y_steps = x_steps * tan(ray_angle);
    map->ray.vertical_intersection_x = map->ray.begin_x;
    map->ray.vertical_intersection_y = map->ray.begin_y;
    while (floor(map->ray.vertical_intersection_x)   <  map->nbr_colums * GRID_SIZE  && floor(map->ray.vertical_intersection_x) >= 0
            && floor(map->ray.vertical_intersection_y) < map->nbr_lines * GRID_SIZE && floor(map->ray.vertical_intersection_y) >= 0)
    {
        double  tmp_x = map->ray.vertical_intersection_x;
        if (cos(ray_angle) < 0)
            tmp_x--;
        if (map->map[(int)floor(map->ray.vertical_intersection_y / GRID_SIZE)][(int)floor(tmp_x / GRID_SIZE)] != '0')
        {
            return (map);
        }
        map->ray.vertical_intersection_x += x_steps;
        map->ray.vertical_intersection_y += y_steps;
    }
    if (map->ray.vertical_intersection_x > map->nbr_colums * GRID_SIZE)
        map->ray.vertical_intersection_x = map->nbr_colums * GRID_SIZE;
    if (map->ray.vertical_intersection_y > map->nbr_lines * GRID_SIZE)
        map->ray.vertical_intersection_y = map->nbr_lines * GRID_SIZE;
    if (map->ray.vertical_intersection_x < 0)
        map->ray.vertical_intersection_x = 0;
    if (map->ray.vertical_intersection_y < 0)
        map->ray.vertical_intersection_y = 0;
    return (map);
}

t_map   *horizontal_intersection(t_map *map, double ray_angle)
{
    double  x_steps;
    double  y_steps;

    y_steps = GRID_SIZE;
    map->ray.begin_y = floor(map->player.y / GRID_SIZE) * GRID_SIZE;
    if (sin(ray_angle) < 0)
    {
        y_steps *= -1;
    }
    else
        map->ray.begin_y += GRID_SIZE;
    map->ray.begin_x = map->player.x + (map->ray.begin_y - map->player.y) / tan(ray_angle);
    x_steps = y_steps / tan(ray_angle);
    map->ray.horizontal_intersection_x = map->ray.begin_x;
    map->ray.horizontal_intersection_y = map->ray.begin_y;
    while (floor(map->ray.horizontal_intersection_x) < map->nbr_colums * GRID_SIZE  && floor(map->ray.horizontal_intersection_x) >= 0
            && floor(map->ray.horizontal_intersection_y) < map->nbr_lines * GRID_SIZE && floor(map->ray.horizontal_intersection_y) >= 0)
    {
        double tmp_y = map->ray.horizontal_intersection_y;
        if (sin(ray_angle) < 0)
            tmp_y--;
        if (map->map[(int)floor(tmp_y / GRID_SIZE)][(int)floor(map->ray.horizontal_intersection_x / GRID_SIZE)] != '0')
        {
            return (map);
        }
        map->ray.horizontal_intersection_x += x_steps;
        map->ray.horizontal_intersection_y += y_steps;
    }
    if (map->ray.horizontal_intersection_x > map->nbr_colums * GRID_SIZE)
        map->ray.horizontal_intersection_x = map->nbr_colums * GRID_SIZE;
    if (map->ray.horizontal_intersection_y > map->nbr_lines * GRID_SIZE)
        map->ray.horizontal_intersection_y = map->nbr_lines * GRID_SIZE;
    if (map->ray.horizontal_intersection_x < 0)
        map->ray.horizontal_intersection_x = 0;
    if (map->ray.horizontal_intersection_y < 0)
        map->ray.horizontal_intersection_y = 0;
    return (map);
}

t_map   *cast_ray(t_map *map, double ray_angle)
{
    map = horizontal_intersection(map, ray_angle);
    map = vertical_intersection(map, ray_angle);

    map->ray.horizontal_distance = distance_between_two_points(map->player.x, map->player.y, map->ray.horizontal_intersection_x, map->ray.horizontal_intersection_y);
    map->ray.vertical_distance = distance_between_two_points(map->player.x, map->player.y, map->ray.vertical_intersection_x, map->ray.vertical_intersection_y);
    return (map);
}

t_map   *casting_rays(t_map *map)
{
    double  ray_angle;

    ray_angle = map->ray.ray_angle;
    
    for (int i = 0; i < map->ray.nbr_rays; i++)
    {
        map = cast_ray(map, ray_angle);
        if (map->ray.horizontal_distance < map->ray.vertical_distance)
        {
            draw_line(*map, map->player.x, map->player.y, map->ray.horizontal_intersection_x,map->ray.horizontal_intersection_y,0xff0000);
        }
        else
        {
            draw_line(*map, map->player.x, map->player.y, map->ray.vertical_intersection_x,map->ray.vertical_intersection_y,0xff0000);
        }
        ray_angle += (double)map->player.field_of_view / map->ray.nbr_rays;
    }
    return (map);
}

