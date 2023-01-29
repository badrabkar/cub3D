/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:48:26 by babkar            #+#    #+#             */
/*   Updated: 2023/01/28 20:29:07 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_game	initialize_struct(void)
{
	t_game	game;

	game.n_texture_xpm = NULL;
	game.s_texture_xpm = NULL;
	game.e_texture_xpm = NULL;
	game.w_texture_xpm = NULL;
	game.nbr_colums = 0;
	game.nbr_lines = 0;
	game.map = NULL;
	return (game);
}
