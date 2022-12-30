/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:58:50 by babkar            #+#    #+#             */
/*   Updated: 2022/12/30 19:09:17 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void    draw_square(t_map map, int i, int j, int color)
{
    for (int k = i * 10; k < (i * 10) + 10; k = k + 1)
        for(int l = j * 10 ; l < (j * 10) + 10; l = l + 1)
            my_mlx_pixel_put(&map.img, l, k, color);
}

void    draw_line(t_map map, double beginX, double beginY, double endX, double endY, int color)
{
    double deltaX = endX - beginX;
    double deltaY = endY - beginY;

    double steps = fabs(deltaX) > fabs(deltaY) ? fabs(deltaX) : fabs(deltaY);
    double incrementX = deltaX / steps;
    double incrementY = deltaY / steps;

    for (int i = 0; i < steps; i++)
    {
        my_mlx_pixel_put(&map.img, beginX, beginY, color);
        beginX += incrementX;
        beginY += incrementY;
    }
}

double  degtorad(int degre)
{
    return ((double)degre * M_PI / 180);
}

int  draw_mini(t_map *map)
{
    if (map->img.img)
        mlx_destroy_image(map->mlx.mlx, map->img.img);
    mlx_clear_window(map->mlx.mlx, map->mlx.win);
    map->img.img = mlx_new_image(map->mlx.mlx, 1920, 1080);
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bits_per_pixel, &map->img.line_length, &map->img.endian);
	my_mlx_pixel_put(&map->img, 5, 5, 0x00FF0000);
    for (int i = 0; i < 14; i++)
    {
        for (int j = 0; map->map[i][j]; j++)
        {
            if (map->map[i][j] == '1')
                draw_square(*map, i, j, 0xff0000);
        }
    }
    draw_square(*map, (int)map->player.y, (int)map->player.x, 0x0000ff);
    double x;
    double y;
    x = (int)map->player.x * 10 + 5;
    y = (int)map->player.y * 10 + 5;
    draw_line(*map,x,y ,x + 32 * cos(map->player.rotation_angle),y + 32 * sin(map->player.rotation_angle),0x00ff00);
    mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->img.img, 0, 0);
    return (0);
}

int	ft_exit(t_map *map)
{
    map = NULL;
    exit(0);
    return (0);
}

t_map *ft_move_up(t_map *map)
{
    map->player.x += cos(map->player.rotation_angle) * map->player.move_speed;
    printf("angle : %f\n", map->player.rotation_angle);
    printf("x : %d\n",(int)map->player.x);
    map->player.y += sin(map->player.rotation_angle) * map->player.move_speed;
    printf("y : %d\n",(int)map->player.y);
    return (map);
}

t_map *ft_move_down(t_map *map)
{
    map->player.x -= cos(map->player.rotation_angle) * map->player.move_speed;
    map->player.y -= sin(map->player.rotation_angle) * map->player.move_speed;
    return (map);
}

t_map *ft_move_right(t_map *map)
{
    map->player.x += sin(map->player.rotation_angle) * map->player.move_speed;
    map->player.y -= cos(map->player.rotation_angle) * map->player.move_speed;
    return (map);
}
t_map *ft_move_left(t_map *map)
{
    map->player.x -= sin(map->player.rotation_angle) * map->player.move_speed;
    map->player.y += cos(map->player.rotation_angle) * map->player.move_speed;
    return (map);
}

t_map   *turn_left(t_map *map)
{
    if ((int)map->player.rotation_angle == (int)(2 * M_PI))
    {
        map->player.rotation_angle = 0;
        return (map);
    }
    map->player.rotation_angle += map->player.rotation_speed;
    return (map); 
}

t_map   *turn_right(t_map *map)
{
    if ((int)map->player.rotation_angle == 0)
    {
        map->player.rotation_angle = 2 * M_PI;
        return (map);
    }
    map->player.rotation_angle -= map->player.rotation_speed;
    return (map); 
}

int	ft_move(int keycode, t_map *map)
{
    if (keycode == LEFT_ARROW_KEY)
        map = turn_left(map);
    if (keycode == RIGHT_ARROW_KEY)
        map = turn_right(map);
    if (keycode == W_KEY)
        map = ft_move_up(map);
    if (keycode == S_KEY)
        map = ft_move_down(map);
    if (keycode == A_KEY)
        map = ft_move_right(map);
    if (keycode == D_KEY)
        map = ft_move_left(map);
    if (keycode == ESC_KEY)
	{
		mlx_destroy_window(map->mlx.mlx, map->mlx.win);
		exit(0);
	}
	return (0);
}

int ft_function(t_map *map)
{
    printf("%d\n", (int)map->player.y);
    return (0);
}

t_map   get_info(t_map map)
{
    mlx_clear_window(map.mlx.mlx, map.mlx.win);
    for (int i = 0; i < 14; i++)
    {
        for (int j = 0; map.map[i][j]; j++)
        {
            if (map.map[i][j] == 'N' || map.map[i][j] == 'W' || map.map[i][j] == 'E' || map.map[i][j] == 'S')
            {
                map.player.x = j;
                map.player.y = i;
                map.player.view = map.map[i][j];
            }
        }
    }
    return (map);
}

int main(int argc, char **argv)
{
    t_map   map;
    
    if (argc != 2)
        return (1);
    map = parse(argv);
    print_map(map);
	ft_window(&map.mlx);
    map = get_info(map);
    map = player_init(map);
    mlx_hook(map.mlx.win, 2, 0, ft_move, &map);
	// mlx_hook(map.mlx.win, 3, 0, ft_reset, &map);
	mlx_loop_hook(map.mlx.mlx, draw_mini, &map);
    mlx_hook(map.mlx.win, 17, 0, ft_exit, &map);
    mlx_loop(&map.mlx);
    return 0;
}