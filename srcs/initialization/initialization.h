/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:45:01 by babkar            #+#    #+#             */
/*   Updated: 2023/01/29 01:55:12 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZATION_H
# define INITIALIZATION_H

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
	int	trgb;
}t_color;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		window_width;
	int		window_heigth;
}t_mlx;

typedef struct s_ray
{
	double	begin_x;
	double	begin_y;
	double	end_x;
	double	end_y;
	double	h_intrsct_x;
	double	h_intrsct_y;
	double	v_intrsct_x;
	double	v_intrsct_y;
	double	v_dist;
	double	h_dist;
	int		nbr_rays;
	double	angle_speed;
	double	angle;
}t_ray;

typedef struct s_parse
{
	char	*line;
	int		fd;
	char	**map_str;
}t_parse;

typedef struct s_wall
{
	int		start;
	int		end;
	double	height;
}t_wall;

typedef struct s_player
{
	double	x;
	double	y;
	char	view;
	double	field_of_view;
	int		move_horizontaly;
	int		move_verticaly;
	int		rotate;
	double	rotation_angle;
	double	move_speed;
	double	rotation_speed;
}t_player;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		*addr_int;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		size;
}t_img;

typedef struct s_game
{
	char		*n_texture_xpm;
	char		*s_texture_xpm;
	char		*w_texture_xpm;
	char		*e_texture_xpm;
	t_img		n_texture;
	t_img		s_texture;
	t_img		w_texture;
	t_img		e_texture;
	t_ray		ray;
	t_color		floor;
	t_color		ceiling;
	t_mlx		mlx;
	t_player	player;
	t_img		img;
	t_wall		wall;
	t_parse		parse;
	int			nbr_colums;
	int			nbr_lines;
	char		**map;
}t_game;

t_game	initialize_struct(void);
t_game	player_init(t_game	game);
t_game	ray_init(t_game	map);
t_game	textures_init(t_game game);
void	ft_window(t_mlx *mlx, t_game game);

#endif