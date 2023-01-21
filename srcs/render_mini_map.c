/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mini_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:49:17 by babkar            #+#    #+#             */
/*   Updated: 2023/01/19 00:15:18 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int equal(double a, double b)
{
    return fabs(a - b) < 1e-4;
}
 
// t_map   *cast_ray(t_map *map, double ray_angle)
// {
//     double  angle_cos = cos(ray_angle);
//     double  angle_sin = sin(ray_angle);
//     double  next_horizantal_intersection_x = 0;
//     double  next_horizantal_intersection_y = 0;
//     double step;
    
//     step = 1;
//     next_horizantal_intersection_x = map->player.x + (double)step * angle_cos;
//     next_horizantal_intersection_y = map->player.y + (double)step * angle_sin;
//     while (next_horizantal_intersection_x <= map->nbr_colums * GRID_SIZE && next_horizantal_intersection_y <= map->nbr_lines * GRID_SIZE
//         && floor(next_horizantal_intersection_y) >= 0 && floor(next_horizantal_intersection_x) >= 0)
//     {
//         if (map->map[(int)floor(next_horizantal_intersection_y / GRID_SIZE)][(int)floor(next_horizantal_intersection_x / GRID_SIZE)] != '0')
//         {
            
//             map->ray.end_x = next_horizantal_intersection_x;
//             map->ray.end_y = next_horizantal_intersection_y;
//             draw_line(*map, map->player.x, map->player.y, map->ray.end_x, map->ray.end_y, 0xff0000);
//             return (map);
//         }
//         else if (map->map[(int)floor(next_horizantal_intersection_y / GRID_SIZE)][(int)floor((next_horizantal_intersection_x + 1) / GRID_SIZE)] != '0')
//         {
//             map->ray.end_x = next_horizantal_intersection_x;
//             map->ray.end_y = next_horizantal_intersection_y;
//             draw_line(*map, map->player.x, map->player.y, map->ray.end_x, map->ray.end_y, 0xff0000);
//             return (map);
//         }
//         else
//         {
//             next_horizantal_intersection_x = map->player.x + (double)step * angle_cos;
//             next_horizantal_intersection_y = map->player.y + (double)step * angle_sin;
//             step += 1;
//         }
//     }
//     return map;
// }


t_map *render_mini_map(t_map *map)
{
    double x;
    double y;
    for (int i = 0; i < map->nbr_lines; i++)
    {
        for (int j = 0; map->map[i][j]; j++)
        {
            if (map->map[i][j] == '1')
            {
                map->img.size = 10;
                draw_square(*map, i, j, 0xffffff);
            }
            if (map->map[i][j] == '0')
            {
                map->img.size = 10;
                draw_square(*map, i,j, 0x000000);
            }
        }
    }


    
    for (int k = map->player.y - 3; k < (map->player.y + 3 ); k = k + 1)
    {
        for(int l = map->player.x - 3; l < (map->player.x + 3 ); l = l + 1)
        {
            puts("||");
            my_mlx_pixel_put(&map->img, l, k, 0x0000ff);
        }
    }
    map->img.size = 10;
    draw_square(*map, map->player.y,map->player.x, 0x000000);

    
    x = map->player.x;
    y = map->player.y;
    map = casting_rays(map);
    draw_line(*map, x, y, x + 10 * cos(map->player.rotation_angle), y + 10 * sin(map->player.rotation_angle),0x0000ff);
    return (map);
}