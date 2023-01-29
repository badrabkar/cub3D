/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:23:44 by babkar            #+#    #+#             */
/*   Updated: 2023/01/27 04:29:39 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_game	north_texture(t_game game, int width, int heigth)
{
	game.n_texture.img = mlx_xpm_file_to_image(game.mlx.mlx,
			game.n_texture_xpm, &width, &heigth);
	if (!game.n_texture.img)
		puterr("mlx_xpm_file_to_image failed!");
	game.n_texture.addr_int = (int *)mlx_get_data_addr(game.n_texture.img,
			&game.n_texture.bits_per_pixel, &game.n_texture.line_length,
			&game.n_texture.endian);
	if (!game.n_texture.addr_int)
		puterr("mlx_get_data_addr failed!");
	return (game);
}

t_game	south_texture(t_game game, int width, int heigth)
{
	game.s_texture.img = mlx_xpm_file_to_image(game.mlx.mlx,
			game.s_texture_xpm, &width, &heigth);
	if (!game.s_texture.img)
		puterr("mlx_xpm_file_to_image failed!");
	game.s_texture.addr_int = (int *)mlx_get_data_addr(game.s_texture.img,
			&game.s_texture.bits_per_pixel, &game.s_texture.line_length,
			&game.s_texture.endian);
	if (!game.s_texture.addr_int)
		puterr("mlx_get_data_addr failed!");
	return (game);
}

t_game	east_texture(t_game game, int width, int heigth)
{
	game.e_texture.img = mlx_xpm_file_to_image(game.mlx.mlx,
			game.e_texture_xpm, &width, &heigth);
	if (!game.e_texture.img)
		puterr("mlx_xpm_file_to_image failed!");
	game.e_texture.addr_int = (int *)mlx_get_data_addr(game.e_texture.img,
			&game.e_texture.bits_per_pixel, &game.e_texture.line_length,
			&game.e_texture.endian);
	if (!game.e_texture.addr_int)
		puterr("mlx_get_data_addr failed!");
	return (game);
}

t_game	west_texture(t_game game, int width, int heigth)
{
	game.w_texture.img = mlx_xpm_file_to_image(game.mlx.mlx,
			game.w_texture_xpm, &width, &heigth);
	if (!game.w_texture.img)
		puterr("mlx_xpm_file_to_image failed!");
	game.w_texture.addr_int = (int *)mlx_get_data_addr(game.w_texture.img,
			&game.w_texture.bits_per_pixel, &game.w_texture.line_length,
			&game.w_texture.endian);
	if (!game.w_texture.addr_int)
		puterr("mlx_get_data_addr failed!");
	return (game);
}

t_game	textures_init(t_game game)
{
	int	width;
	int	heigth;

	width = 64;
	heigth = 64;
	game = east_texture(game, width, heigth);
	game = west_texture(game, width, heigth);
	game = north_texture(game, width, heigth);
	game = south_texture(game, width, heigth);
	free(game.e_texture_xpm);
	free(game.s_texture_xpm);
	free(game.n_texture_xpm);
	free(game.w_texture_xpm);
	return (game);
}
