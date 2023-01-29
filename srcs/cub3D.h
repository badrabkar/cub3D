/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:00:58 by babkar            #+#    #+#             */
/*   Updated: 2023/01/28 20:21:00 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <mlx.h>
# include "../srcs/utils/utils.h"
# include "../srcs/initialization/initialization.h"
# include "../srcs/parsing/parsing.h"
# include <math.h>

# define ESC_KEY 53
# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2
# define LEFT_ARROW_KEY 123
# define RIGHT_ARROW_KEY 124
# define GRID_SIZE 64
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 720
# define WALL_STRIP_WIDTH 1

int		render(t_game *map);
t_game	player_init(t_game game);
void	ft_window(t_mlx *mlx, t_game game);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
t_game	*update_player_position(t_game *game);
t_game	*render_walls(t_game *game);
t_game	*cast_ray(t_game *game, double ray_angle);
int		create_trgb(int t, int r, int g, int b);
t_game	*wall_collision_and_sliding(t_game *game, double old_x, double old_y);
t_game	*corners(t_game *game, double old_x, double old_y);

#endif