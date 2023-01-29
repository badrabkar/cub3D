/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:03:14 by babkar            #+#    #+#             */
/*   Updated: 2023/01/27 04:29:39 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_game	get_info(t_game map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map.nbr_lines)
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] == 'N' || map.map[i][j] == 'W'
				|| map.map[i][j] == 'E' || map.map[i][j] == 'S')
			{
				map.player.x = (j + 0.5) * GRID_SIZE;
				map.player.y = (i + 0.5) * GRID_SIZE;
				map.player.view = map.map[i][j];
				map.map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	return (map);
}

t_game	player_init(t_game	game)
{
	game = get_info(game);
	if (game.player.view == 'N')
		game.player.rotation_speed = 135;
	if (game.player.view == 'S')
		game.player.rotation_speed = 45;
	if (game.player.view == 'E')
		game.player.rotation_speed = 0;
	if (game.player.view == 'W')
		game.player.rotation_speed = 90;
	game.player.rotation_angle = game.player.rotation_speed * M_PI / 90;
	game.player.move_speed = (double)GRID_SIZE / 10 * 1.2;
	game.player.move_horizontaly = -1;
	game.player.move_verticaly = -1;
	game.player.rotate = -1;
	game.player.field_of_view = degree_to_radian(60);
	return (game);
}
