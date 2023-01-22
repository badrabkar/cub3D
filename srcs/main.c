/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:58:50 by babkar            #+#    #+#             */
/*   Updated: 2023/01/22 00:26:12 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_exit(t_map *map)
{
    map = NULL;
    exit(0);
    return (0);
}

int	ft_move(int keycode, t_map *map)
{
    if (keycode == LEFT_ARROW_KEY)
        map->player.rotate = keycode;
    if (keycode == RIGHT_ARROW_KEY)
        map->player.rotate = keycode;
    if (keycode == W_KEY)
        map->player.move_verticaly = keycode;
    if (keycode == S_KEY)
        map->player.move_verticaly = keycode;
    if (keycode == A_KEY)
        map->player.move_horizontaly = keycode;
    if (keycode == D_KEY)
        map->player.move_horizontaly = keycode;
    if (keycode == ESC_KEY)
	{
		mlx_destroy_window(map->mlx.mlx, map->mlx.win);
		exit(0);
	}
	return (0);
}

int	ft_reset(int keycode, t_map *map)
{
    if (keycode == LEFT_ARROW_KEY)
        map->player.rotate = -1;
    if (keycode == RIGHT_ARROW_KEY)
        map->player.rotate = -1;
    if (keycode == W_KEY)
        map->player.move_verticaly = -1;
    if (keycode == S_KEY)
        map->player.move_verticaly = -1;
    if (keycode == A_KEY)
        map->player.move_horizontaly = -1;
    if (keycode == D_KEY)
        map->player.move_horizontaly = -1;
	return (0);
}

t_map   get_info(t_map map)
{
    for (int i = 0; i < map.nbr_lines; i++)
    {
        for (int j = 0; map.map[i][j]; j++)
        {
            if (map.map[i][j] == 'N' || map.map[i][j] == 'W' || map.map[i][j] == 'E' || map.map[i][j] == 'S')
            {
                map.player.x = (j + 0.5) * GRID_SIZE;
                map.player.y = (i + 0.5) * GRID_SIZE;
                map.player.view = map.map[i][j];
                map.map[i][j] = '0';
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
	ft_window(&map.mlx, map);
    print_map(map);
    map = get_info(map);
    map = player_init(map);
    map = textures_init(map);
    mlx_hook(map.mlx.win, 2, 0, ft_move, &map);
	mlx_hook(map.mlx.win, 3, 0, ft_reset, &map);
    mlx_hook(map.mlx.win, 17, 0, ft_exit, &map);
	mlx_loop_hook(map.mlx.mlx, render, &map);
    mlx_loop(&map.mlx);
    return 0;
}