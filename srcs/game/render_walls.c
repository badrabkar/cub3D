/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:04:52 by babkar            #+#    #+#             */
/*   Updated: 2023/01/27 04:29:39 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	*get_color_from_texture(t_game *game, double ray_angle)
{
	if (game->ray.h_dist < game->ray.v_dist)
	{
		if (ray_angle >= M_PI && ray_angle <= 2 * M_PI)
			return (game->n_texture.addr_int);
		else
			return (game->s_texture.addr_int);
	}
	else
	{
		if (cos(ray_angle) > 0)
			return (game->e_texture.addr_int);
		else
			return (game->w_texture.addr_int);
	}
	return (0x000000);
}

float	calculate_wall_heigth(t_game *game, double ray_angle)
{
	double	distance_from_player_to_plane;
	double	projected_wall_height;
	double	distance_to_wall;

	if (game->ray.h_dist < game->ray.v_dist)
		distance_to_wall = dist_between_two_points(game->player.x,
				game->player.y, game->ray.h_intrsct_x, game->ray.h_intrsct_y);
	else
		distance_to_wall = dist_between_two_points(game->player.x,
				game->player.y, game->ray.v_intrsct_x, game->ray.v_intrsct_y);
	distance_to_wall *= cos(ray_angle - game->player.rotation_angle);
	distance_from_player_to_plane = ((double)(WINDOW_WIDTH) / 2)
		/ tan(game->player.field_of_view / 2);
	projected_wall_height = (GRID_SIZE / distance_to_wall)
		* distance_from_player_to_plane;
	return (projected_wall_height);
}

void	draw_wall(t_game *game, int *color, int texture_x, int x)
{
	int	texture_y;

	while (game->wall.start <= game->wall.end
		&& game->wall.start < WINDOW_HEIGHT)
	{
		texture_y = game->wall.start + ((int)game->wall.height / 2);
		texture_y -= WINDOW_HEIGHT / 2;
		texture_y *= ((float)GRID_SIZE / (int)game->wall.height);
		texture_y *= GRID_SIZE;
		my_mlx_pixel_put(&game->img, x, game->wall.start,
			color[texture_y + texture_x]);
		game->wall.start++;
	}
}

void	render_wall(t_game *game, int x, double ray_angle)
{
	int	texture_x;
	int	*color;

	color = get_color_from_texture(game, ray_angle);
	if (game->ray.h_dist < game->ray.v_dist)
		texture_x = ((int)game->ray.h_intrsct_x % GRID_SIZE);
	else
		texture_x = ((int)game->ray.v_intrsct_y % GRID_SIZE);
	game->wall.height = calculate_wall_heigth(game, ray_angle);
	game->wall.start = (WINDOW_HEIGHT / 2) - ((int)game->wall.height / 2);
	if (game->wall.start < 0)
		game->wall.start = 0;
	game->wall.end = game->wall.start + (int)game->wall.height;
	draw_wall(game, color, texture_x, x);
}

t_game	*render_walls(t_game *game)
{
	double	ray_angle;
	int		i;

	i = 0;
	ray_angle = game->ray.angle;
	while (i < game->ray.nbr_rays)
	{
		game = cast_ray(game, ray_angle);
		render_wall(game, i, ray_angle);
		ray_angle += game->player.field_of_view / game->ray.nbr_rays;
		i++;
	}
	return (game);
}
