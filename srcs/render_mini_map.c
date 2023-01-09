/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mini_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:49:17 by babkar            #+#    #+#             */
/*   Updated: 2023/01/09 14:07:34 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int equal(double a, double b)
{
    return fabs(a - b) < 1e-4;
}

double  normalizeAngle(double angle)
{
    // angle = remainder(angle, 2 * M_PI);
    angle = fmod(angle, 2 * M_PI);
    if (angle < 0)
    {
        angle = angle + 2 * M_PI;
    }
    return angle;
}

int	iswall(t_map *r, double new_x, double new_y)
{
	int	x;
	int	y;
	int	line;

	if (new_y > 0 && floor(new_y) < r->nbr_lines)
		line = ft_strlen(r->map[(int)(new_y)]);
	if (new_y < 0 || floor(new_y) > r->nbr_lines \
	|| new_x < 0 || (new_x) > line)
		return (1);
	x = floor(new_x );
	y = floor(new_y );
	if (r->map[y] && r->map[y][x] \
	&& (r->map[y][x] == '1' \
	|| r->map[y][x] == ' ' \
	|| r->map[y][x] == '\0'))
		return (1);
	return (0);
}

t_map   *cast_ray(t_map *map)
{
    double  x_steps;
    double  y_steps;
    
    y_steps = 1;
    x_steps = y_steps / tan(map->ray.ray_angle);
    map->ray.ray_angle = normalizeAngle(map->ray.ray_angle);

    
    map->ray.begin_y = floor(map->player.y);
    if (sin(map->ray.ray_angle) < 0)
    {
        y_steps *= -1;
    }
    map->ray.begin_x = map->player.x + (map->ray.begin_y - map->player.y) / tan(map->ray.ray_angle);
    if (cos(map->ray.ray_angle) < 0 )
    {
        x_steps *= -1;
    }
    // printf("%f ", map->ray.ray_angle + degree_to_radian(30));
    // printf("%f\n", map->player.rotation_angle);
    map->ray.end_x = map->ray.begin_x;
    map->ray.end_y = map->ray.begin_y;
    while (floor(map->ray.end_x)   <  map->nbr_colums  && floor(map->ray.end_x) >= 0
            && floor(map->ray.end_y) < map->nbr_lines && floor(map->ray.end_y) >= 0)
    {
        if (map->map[(int)floor(map->ray.end_y)][(int)floor(map->ray.end_x)] == '1'
            || map->map[(int)floor(map->ray.end_y )][(int)floor(map->ray.end_x)] == '2'
            || map->map[(int)floor(map->ray.end_y)][(int)floor(map->ray.end_x)] == '\0')
        {
            break;
        }
        map->ray.end_x += x_steps;
        map->ray.end_y += y_steps;
    }
    printf("map->ray.end_x : %f ", map->ray.end_x);
    printf("map->ray.end_y : %f\n", map->ray.end_y);
    return (map);
}

int  render_mini_map(t_map *map)
{
    double old_playerX;
    double old_playerY;
    double x;
    double y;
    old_playerX = map->player.x;
    old_playerY = map->player.y;
    map = update_player_position(map);
    map = cast_ray(map);

    if (map->img.img)
        mlx_destroy_image(map->mlx.mlx, map->img.img);
    mlx_clear_window(map->mlx.mlx, map->mlx.win);
    map->img.img = mlx_new_image(map->mlx.mlx, map->nbr_colums * GRID_SIZE, map->nbr_lines * GRID_SIZE);
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bits_per_pixel, &map->img.line_length, &map->img.endian);
    for (int i = 0; i < map->nbr_lines; i++)
    {
        for (int j = 0; map->map[i][j]; j++)
        {
            if (map->map[i][j] == '1')
            {
                map->img.size = GRID_SIZE;
                draw_square(*map, i, j, 0xffffff);
            }
            if (map->map[i][j] == '0')
            {
                map->img.size = GRID_SIZE;
                draw_square(*map, i,j, 0x000000);
            }
        }
    }
    if (map->map[(int)map->player.y][(int)old_playerX] == '1'
        ||  map->map[(int)old_playerY][(int)map->player.x] == '1'
        || map->map[(int)map->player.y][(int)map->player.x] == '2')
    {
            map->player.x = old_playerX;
            map->player.y = old_playerY;
    }
    map->img.size = 10;
    draw_square(*map, map->player.y, map->player.x, 0x0000ff);
    x = map->player.x * GRID_SIZE;
    y = map->player.y * GRID_SIZE;
    draw_line(*map, x, y, x + GRID_SIZE * cos(map->player.rotation_angle), y + GRID_SIZE * sin(map->player.rotation_angle),0x0000ff);
    draw_line(*map, x, y, x + (map->ray.end_x) * cos(map->ray.ray_angle), y + (map->ray.end_y) * sin(map->ray.ray_angle), 0xff0000);
    mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->img.img, 0, 0);
    return (0);
}