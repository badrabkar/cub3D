/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:40:08 by babkar            #+#    #+#             */
/*   Updated: 2023/02/04 20:35:35 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_game	*draw_square(t_game *game, double i, double j, int color)
{
	int	x;
	int	y;

	y = i * 10;
	while (y < (i * 10) + 10)
	{
		x = j * 10;
		while (x < (j * 10) + 10)
		{
			my_mlx_pixel_put(&game->img, x, y, color);
			x++;
		}
		y++;
	}
	return (game);
}

t_game	*render_minimap(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = (int)(game->player.x / GRID_SIZE);
	y = (int)(game->player.y / GRID_SIZE);
	i = y - 5;
	while (game->map[i] && i < y + 5)
	{
		j = x - 5;
		while (j < x + 5)
		{
			if(i < 0 || j < 0)
				game = draw_square(game, i - y + 5, j - x + 5, 0x808080);
			else if (game->map[i][j] == '0')
					game = draw_square(game, i - y + 5, j - x + 5, 0x000000);
			else if (game->map[i][j] == '1')
					game = draw_square(game, i - y + 5, j - x + 5, 0xffffff);
			else if (game->map[i][j] == '3')
					game = draw_square(game, i - y + 5, j - x + 5, 0x00ff00);
			else
				game = draw_square(game, i - y + 5, j - x + 5, 0x808080);
			j++;
		}
		i++;
	}
	game = draw_square(game, 5, 5, 0xff0000);
	return (game);
}
