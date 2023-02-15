/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:44:58 by babkar            #+#    #+#             */
/*   Updated: 2023/02/04 20:29:40 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_game	door_texture(t_game game)
{
	game.door.width = 64;
	game.door.heigth = 64;
	game.door.img = mlx_xpm_file_to_image(game.mlx.mlx,
			"./textures/door.xpm", &game.door.width, &game.door.heigth);
	if (!game.door.img)
		puterr("mlx_xpm_file_to_image failed!");
	game.door.addr_int = (int *)mlx_get_data_addr(game.door.img,
			&game.door.bits_per_pixel, &game.door.line_length,
			&game.door.endian);
	if (!game.door.addr_int)
		puterr("mlx_get_data_addr failed!");
	return (game);
}