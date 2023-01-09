/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:40:54 by babkar            #+#    #+#             */
/*   Updated: 2023/01/09 15:52:47 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_window(t_mlx *mlx, t_map map)
{
	mlx->mlx = mlx_init();
	mlx->win  = mlx_new_window(mlx->mlx, map.nbr_colums * GRID_SIZE,  map.nbr_lines * GRID_SIZE, "cub3d");
}
