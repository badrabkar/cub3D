/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:58:50 by babkar            #+#    #+#             */
/*   Updated: 2023/01/12 15:37:52 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_exit(t_map *map)
{
    map = NULL;
    exit(0);
    return (0);
}
int	ft_move(int keycode, t_map *map)
{
    if (keycode == LEFT_ARROW_KEY)
        map->rotation = -1;
    if (keycode == RIGHT_ARROW_KEY)
        map->rotation = 1;
    if (keycode == W_KEY)
        map->walk_ws = 1;
    if (keycode == S_KEY)
        map->walk_ws = -1;
    if (keycode == A_KEY)
        map->walk_ad = 1;
    if (keycode == D_KEY)
        map->walk_ad = -1;
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
        map->rotation = 0;
    if (keycode == RIGHT_ARROW_KEY)
        map->rotation = 0;
    if (keycode == W_KEY)
        map->walk_ws = 0;
    if (keycode == S_KEY)
        map->walk_ws = 0;
    if (keycode == A_KEY)
        map->walk_ad = 0;
    if (keycode == D_KEY)
        map->walk_ad = 0;
	return (0);
}

t_map   get_info(t_map map)
{
    mlx_clear_window(map.mlx.mlx, map.mlx.win);
    for (int i = 0; i < map.nbr_lines; i++)
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
    // printf("%d\n", map.nbr_lines);
    map = parse(argv);
    print_map(map);
	ft_window(&map.mlx, map);
    map = get_info(map);
    map = player_init(map);
    map.walk_ws = 0;
    map.walk_ad = 0;
    map.rotation = 0;
    mlx_hook(map.mlx.win, 2, 0, ft_move, &map);
	mlx_hook(map.mlx.win, 3, 0, ft_reset, &map);
	mlx_loop_hook(map.mlx.mlx, render_mini_map, &map);
    mlx_hook(map.mlx.win, 17, 0, ft_exit, &map);
    mlx_loop(&map.mlx);
    return 0;
}


// int main(int argc, char **argv)
// {
//     t_map   map;
    
//     if (argc != 2)
//         return (1);
//     map = parse(argv);
//     print_map(map);
// 	ft_window(&map.mlx);
//     map.img.img = mlx_new_image(map.mlx.mlx, 10, 10);
//     map.img.addr = mlx_get_data_addr(map.img.img, &map.img.bits_per_pixel, &map.img.line_length, &map.img.endian);
//     for (int k = 0 * 10; k < (0 * 10) + 10; k = k + 1)
//         for(int l = 0 * 10 ; l < (0 * 10) + 10; l = l + 1)
//             my_mlx_pixel_put(&map.img, l, k, 0x00ff00);
//     mlx_put_image_to_window(map.mlx.mlx, map.mlx.win, map.img.img, 10, 0);
//     printf("%d\n", map.img.bits_per_pixel);
//     // printf("%d\n", map.img.line_length);
//     // printf("%d\n", map.img.endian);
//     // mlx_pixel_put
//     // map = get_info(map);
//     // map = player_init(map);
//     // map.walk_ws = 0;
//     // map.walk_ad = 0;
//     // map.rotation = 0;
//     // mlx_hook(map.mlx.win, 2, 0, ft_move, &map);
// 	// mlx_hook(map.mlx.win, 3, 0, ft_reset, &map);
// 	// mlx_loop_hook(map.mlx.mlx, render_mini_map, &map);
//     // mlx_hook(map.mlx.win, 17, 0, ft_exit, &map);
//     mlx_loop(&map.mlx);
//     return 0;
// }
