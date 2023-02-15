/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:48:26 by babkar            #+#    #+#             */
/*   Updated: 2023/02/05 13:55:25 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_game	initialize_struct(void)
{
	t_game	game;
	
	bzero(&game, sizeof(game));
	return (game);
}
