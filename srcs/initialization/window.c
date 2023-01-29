/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:40:54 by babkar            #+#    #+#             */
/*   Updated: 2023/01/28 20:23:50 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_window(t_mlx *mlx, t_game game)
{
	game.mlx.window_width = WINDOW_WIDTH;
	game.mlx.window_heigth = WINDOW_HEIGHT;
	game.mlx.window_width = fmin(game.mlx.window_width, 1920);
	game.mlx.window_heigth = fmin(game.mlx.window_heigth, 720);
	game.mlx.window_width = fmax(game.mlx.window_width, 50);
	game.mlx.window_heigth = fmax(game.mlx.window_heigth, 50);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, game.mlx.window_width,
			game.mlx.window_heigth, "cub3D");
}
