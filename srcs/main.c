/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:58:50 by babkar            #+#    #+#             */
/*   Updated: 2022/12/28 22:29:18 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	ft_window(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win  = mlx_new_window(mlx->mlx, 1920,  1080, "cub3d");
}

void    draw_rectangle(void *mlx, void *win, int j, int i, int color)
{
    for (int k = i; k < i + GRID_SIZE; k++)
    {
        for(int l = j; l < j + GRID_SIZE; l++)
            mlx_pixel_put(mlx, win, l, k, color);
    }
}

void    draw_line(t_map map, int beginX, int beginY, int endX, int endY, int color)
{
    double deltaX = endX - beginX; // 10
    double deltaY = endY - beginY; // 0

    int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
    deltaX /= pixels; // 1
    deltaY /= pixels; // 0
    double pixelX = beginX;
    double pixelY = beginY;
    while (pixels)
    {
        mlx_pixel_put(map.mlx.mlx, map.mlx.win, pixelX, pixelY, color);
        pixelX += deltaX;
        pixelY += deltaY;
        --pixels;
    }
}

double  degtorad(int degre)
{
    return ((double)degre * M_PI / 180);
}

t_map   draw_mini_map(t_map map)
{
    int x;
    int y;
    mlx_clear_window(map.mlx.mlx, map.mlx.win);
    for (int i = 0; i < 14; i++)
    {
        for (int j = 0; map.map[i][j]; j++)
        {
            if (map.map[i][j] == '1')
                draw_rectangle(map.mlx.mlx, map.mlx.win, j * GRID_SIZE, i * GRID_SIZE, 0xff0000);
            if (map.map[i][j] == 'N' || map.map[i][j] == 'W')
            {
                draw_rectangle(map.mlx.mlx, map.mlx.win, j * GRID_SIZE, i * GRID_SIZE, 0x0000ff);
                x = j * GRID_SIZE + GRID_SIZE / 2;
                y = i * GRID_SIZE + GRID_SIZE / 2 ;
                map.player.x = j;
                map.player.y = i;
            }
        }
    }
    draw_line(map,x, y,x + 32 * cos(map.player.rotation_angle),y + 32 * sin(map.player.rotation_angle),0x00ff00);
    return (map);
}

t_map   *draw_mini(t_map *map)
{
    mlx_clear_window(map->mlx.mlx, map->mlx.win);
    for (int i = 0; i < 14; i++)
    {
        for (int j = 0; map->map[i][j]; j++)
        {
            if (map->map[i][j] == '1')
                draw_rectangle(map->mlx.mlx, map->mlx.win, j * GRID_SIZE, i * GRID_SIZE, 0xff0000);
        }
    }
    draw_rectangle(map->mlx.mlx, map->mlx.win, map->player.x * GRID_SIZE,   map->player.y  * GRID_SIZE, 0x0000ff);
    int x;
    int y;
    x = map->player.x * GRID_SIZE + GRID_SIZE / 2;
    y = map->player.y * GRID_SIZE + GRID_SIZE / 2;
    draw_line(*map,x,y ,x + 60 * cos(map->player.rotation_angle),y + 60 * sin(map->player.rotation_angle),0x00ff00);
    map->player.rotation_angle = map->player.turn * map->player.rotation_speed;
    return (map);
}

int	ft_exit(t_map *map)
{
    map = NULL;
	exit(0);
	return (0);
}

t_map *ft_move_up(t_map *map)
{
    map->player.walk = 1;
    map->player.x += cos(map->player.rotation_angle) * (map->player.walk * map->player.move_speed);
    map->player.y += sin(map->player.rotation_angle) * (map->player.walk * map->player.move_speed);
    map = draw_mini(map);
    return (map);
}

t_map *ft_move_down(t_map *map)
{
    map->player.walk = -1;
    map->player.x += cos(map->player.rotation_angle) * (map->player.walk * map->player.move_speed);
    map->player.y += sin(map->player.rotation_angle) * (map->player.walk * map->player.move_speed);
    map = draw_mini(map);
    return (map);
}

t_map *ft_move_right(t_map *map)
{
    map->player.turn -= -1;
    map = draw_mini(map);
    return (map);
}
t_map *ft_move_left(t_map *map)
{
    map->player.turn += -1;
    map = draw_mini(map);
    return (map);
}

int	ft_move(int keycode, t_map *map)
{
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

int	ft_reset(int keycode, t_map *map)
{
	if (keycode == W_KEY)
		map->player.walk = 0;
    if (keycode == S_KEY)
 		map->player.walk = 0;
    if (keycode == A_KEY)
		map->player.turn = 0;
    if (keycode == D_KEY)
		map->player.turn = 0;
	return (0);
}

int ft_function(t_map *map)
{
    printf("%d\n", map->player.y);
    return (0);
}
int main(int argc, char **argv)
{
    t_map   map;

    
    if (argc != 2)
        return (1);
        	
    map = parse(argv);
    print_map(map);
    map = player_init(map);
	ft_window(&map.mlx);
    map = draw_mini_map(map);
    mlx_hook(map.mlx.win, 2, 0, ft_move, &map);
	mlx_hook(map.mlx.win, 3, 0, ft_reset, &map);
	// mlx_loop_hook(&map.mlx, ft_function, &map);
    mlx_hook(map.mlx.win, 17, 0, ft_exit, &map);
    mlx_loop(&map.mlx);
    return 0;
}