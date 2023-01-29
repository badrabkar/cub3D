/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision_sliding.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:54:50 by babkar            #+#    #+#             */
/*   Updated: 2023/01/27 04:29:39 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_game	*wall_collision_and_sliding(t_game *game, double old_x, double old_y)
{
	if (game->map[((int)game->player.y + GRID_SIZE / 4) / GRID_SIZE]
		[(int)old_x / GRID_SIZE] == '1')
			game->player.y = old_y;
	if (game->map[(int)old_y / GRID_SIZE]
		[((int)game->player.x + GRID_SIZE / 4) / GRID_SIZE] == '1')
			game->player.x = old_x;
	if (game->map[((int)game->player.y - GRID_SIZE / 4) / GRID_SIZE]
		[(int)old_x / GRID_SIZE] == '1')
		game->player.y = old_y;
	if (game->map[(int)old_y / GRID_SIZE]
		[((int)game->player.x - GRID_SIZE / 4) / GRID_SIZE] == '1')
		game->player.x = old_x;
	return (game);
}

t_game	*corners(t_game *game, double old_x, double old_y)
{
	if (game->map[((int)game->player.y + GRID_SIZE / 10) / GRID_SIZE]
		[((int)game->player.x + GRID_SIZE / 10) / GRID_SIZE] == '1'
		|| game->map[((int)game->player.y - GRID_SIZE / 10) / GRID_SIZE]
		[((int)game->player.x + GRID_SIZE / 10) / GRID_SIZE] == '1'
		|| game->map[((int)game->player.y + GRID_SIZE / 10) / GRID_SIZE]
		[((int)game->player.x - GRID_SIZE / 10) / GRID_SIZE] == '1'
		|| game->map[((int)game->player.y - GRID_SIZE / 10) / GRID_SIZE]
		[((int)game->player.x - GRID_SIZE / 10) / GRID_SIZE] == '1')
	{
		game->player.y = old_y;
		game->player.x = old_x;
	}
	return (game);
}
