/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:58:50 by babkar            #+#    #+#             */
/*   Updated: 2023/01/29 01:37:59 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_exit(t_game *map)
{
	map = NULL;
	exit(0);
	return (0);
}

int	key_press(int keycode, t_game *map)
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

int	key_release(int keycode, t_game *map)
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

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		puterr("enter the valid arguments!!\n");
	check_map_extension(argv[1]);
	game = initialize_struct();
	game = parse(argv, game);
	ft_window(&game.mlx, game);
	game = player_init(game);
	game = ray_init(game);
	game = textures_init(game);
	mlx_hook(game.mlx.win, 2, 0, key_press, &game);
	mlx_hook(game.mlx.win, 3, 0, key_release, &game);
	mlx_hook(game.mlx.win, 17, 0, ft_exit, &game);
	mlx_loop_hook(game.mlx.mlx, render, &game);
	mlx_loop(&game.mlx);
}
