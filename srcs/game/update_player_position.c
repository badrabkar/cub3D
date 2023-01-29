/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_position.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:58:44 by babkar            #+#    #+#             */
/*   Updated: 2023/01/27 04:29:39 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_game	*rotate(t_game *game)
{
	int	k;
	int	n;

	k = 180;
	n = 90;
	if (game->player.rotate == RIGHT_ARROW_KEY)
	{
		game->player.rotation_speed = ((int)game->player.rotation_speed + 1);
		game->player.rotation_speed = (int)game->player.rotation_speed % k;
		game->player.rotation_angle = game->player.rotation_speed * M_PI / n;
		game->ray.angle_speed = ((int)game->ray.angle_speed + 1) % k;
		game->ray.angle = game->ray.angle_speed * M_PI / n;
	}
	if (game->player.rotate == LEFT_ARROW_KEY)
	{
		game->player.rotation_speed = ((int)game->player.rotation_speed + 179);
		game->player.rotation_speed = (int)game->player.rotation_speed % k;
		game->player.rotation_angle = game->player.rotation_speed * M_PI / n;
		game->ray.angle_speed = ((int)game->ray.angle_speed + 179) % k;
		game->ray.angle = game->ray.angle_speed * M_PI / n;
	}
	return (game);
}

t_game	*move_verticaly(t_game *game)
{
	if (game->player.move_verticaly == W_KEY)
	{
		game->player.x += cos(game->player.rotation_angle)
			* game->player.move_speed;
		game->player.y += sin(game->player.rotation_angle)
			* game->player.move_speed;
	}
	if (game->player.move_verticaly == S_KEY)
	{
		game->player.x -= cos(game->player.rotation_angle)
			* game->player.move_speed;
		game->player.y -= sin(game->player.rotation_angle)
			* game->player.move_speed;
	}
	return (game);
}

t_game	*move_horizontaly(t_game *game)
{
	if (game->player.move_horizontaly == D_KEY)
	{
		game->player.x -= sin(game->player.rotation_angle)
			* game->player.move_speed;
		game->player.y += cos(game->player.rotation_angle)
			* game->player.move_speed;
	}
	if (game->player.move_horizontaly == A_KEY)
	{
		game->player.x += sin(game->player.rotation_angle)
			* game->player.move_speed;
		game->player.y -= cos(game->player.rotation_angle)
			* game->player.move_speed;
	}
	return (game);
}

t_game	*update_player_position(t_game *game)
{
	double	old_player_x;
	double	old_player_y;

	old_player_x = game->player.x;
	old_player_y = game->player.y;
	if (game->player.rotate == LEFT_ARROW_KEY
		|| game->player.rotate == RIGHT_ARROW_KEY)
		game = rotate(game);
	if (game->player.move_verticaly == W_KEY
		|| game->player.move_verticaly == S_KEY)
		game = move_verticaly(game);
	if (game->player.move_horizontaly == D_KEY
		|| game->player.move_horizontaly == A_KEY)
		game = move_horizontaly(game);
	game = wall_collision_and_sliding(game, old_player_x, old_player_y);
	game = corners(game, old_player_x, old_player_y);
	return (game);
}
