/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:06:07 by babkar            #+#    #+#             */
/*   Updated: 2023/01/27 04:29:39 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	render_floor(t_game *game)
{
	int	i;
	int	j;

	i = WINDOW_HEIGHT / 2;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(&game->img, j, i, create_trgb(0, game->floor.red,
					game->floor.green, game->floor.blue));
			j++;
		}
		i++;
	}
}

void	render_ceiling(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT / 2)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(&game->img, j, i, create_trgb(0, game->ceiling.red,
					game->ceiling.green, game->ceiling.blue));
			j++;
		}
		i++;
	}
}

int	render(t_game *game)
{
	game = update_player_position(game);
	if (game->img.img)
		mlx_destroy_image(game->mlx.mlx, game->img.img);
	mlx_clear_window(game->mlx.mlx, game->mlx.win);
	game->img.img = mlx_new_image(game->mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
	game->img.addr_int = (int *)mlx_get_data_addr(game->img.img,
			&game->img.bits_per_pixel, &game->img.line_length,
			&game->img.endian);
	render_ceiling(game);
	render_floor(game);
	game = render_walls(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->img.img, 0, 0);
	return (0);
}
