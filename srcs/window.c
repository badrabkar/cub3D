/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:40:54 by babkar            #+#    #+#             */
/*   Updated: 2023/01/09 15:48:44 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_window(t_mlx *mlx, t_map map)
{
	mlx->mlx = mlx_init();
	mlx->win  = mlx_new_window(mlx->mlx, map.nbr_colums * GRID_SIZE, map.nbr_lines * GRID_SIZE, "cub3d");
}
