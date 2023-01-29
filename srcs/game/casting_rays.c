/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:08:13 by babkar            #+#    #+#             */
/*   Updated: 2023/01/27 04:29:39 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_game	*v_intrsct(t_game *game, double angle, double y_steps, double x_steps)
{
	double	tmp;

	while (game->ray.v_intrsct_x < game->nbr_colums * GRID_SIZE
		&& game->ray.v_intrsct_x >= 0
		&& game->ray.v_intrsct_y < game->nbr_lines * GRID_SIZE
		&& game->ray.v_intrsct_y >= 0)
	{
		tmp = game->ray.v_intrsct_x;
		if (cos(angle) < 0)
			tmp--;
		if (cos(angle) > 0)
			tmp++;
		if (game->map[(int)(game->ray.v_intrsct_y / GRID_SIZE)]
			[(int)(tmp / GRID_SIZE)] != '0')
			return (game);
		game->ray.v_intrsct_x += x_steps;
		game->ray.v_intrsct_y += y_steps;
	}
	return (game);
}

t_game	*vertical_intersection(t_game *game, double ray_angle)
{
	double	x_steps;
	double	y_steps;

	x_steps = GRID_SIZE;
	game->ray.begin_x = (int)(game->player.x / GRID_SIZE) * GRID_SIZE;
	if (cos(ray_angle) < 0)
		x_steps *= -1;
	else
		game->ray.begin_x += GRID_SIZE;
	game->ray.begin_y = game->player.y + (game->ray.begin_x - game->player.x)
		* tan(ray_angle);
	y_steps = x_steps * tan(ray_angle);
	game->ray.v_intrsct_x = game->ray.begin_x;
	game->ray.v_intrsct_y = game->ray.begin_y;
	game = v_intrsct(game, ray_angle, y_steps, x_steps);
	return (game);
}

t_game	*h_intrsct(t_game *game, double angle, double y_steps, double x_steps)
{
	double	tmp;

	while (game->ray.h_intrsct_x < game->nbr_colums * GRID_SIZE
		&& game->ray.h_intrsct_x >= 0
		&& game->ray.h_intrsct_y < game->nbr_lines * GRID_SIZE
		&& game->ray.h_intrsct_y >= 0)
	{
		tmp = game->ray.h_intrsct_y;
		if (sin(angle) < 0)
			tmp--;
		if (sin(angle) > 0)
			tmp++;
		if (game->map[(int)(tmp / GRID_SIZE)]
			[(int)(game->ray.h_intrsct_x / GRID_SIZE)] != '0')
			return (game);
		game->ray.h_intrsct_x += x_steps;
		game->ray.h_intrsct_y += y_steps;
	}
	return (game);
}

t_game	*horizontal_intersection(t_game *game, double ray_angle)
{
	double	x_steps;
	double	y_steps;

	y_steps = GRID_SIZE;
	game->ray.begin_y = (int)(game->player.y / GRID_SIZE) * GRID_SIZE;
	if (sin(ray_angle) < 0)
		y_steps *= -1;
	else
		game->ray.begin_y += GRID_SIZE;
	game->ray.begin_x = game->player.x + (game->ray.begin_y - game->player.y)
		/ tan(ray_angle);
	x_steps = y_steps / tan(ray_angle);
	game->ray.h_intrsct_x = game->ray.begin_x;
	game->ray.h_intrsct_y = game->ray.begin_y;
	game = h_intrsct(game, ray_angle, y_steps, x_steps);
	return (game);
}

t_game	*cast_ray(t_game *map, double ray_angle)
{
	map = horizontal_intersection(map, ray_angle);
	map = vertical_intersection(map, ray_angle);
	map->ray.h_dist = dist_between_two_points(map->player.x, map->player.y,
			map->ray.h_intrsct_x, map->ray.h_intrsct_y);
	map->ray.v_dist = dist_between_two_points(map->player.x, map->player.y,
			map->ray.v_intrsct_x, map->ray.v_intrsct_y);
	return (map);
}
