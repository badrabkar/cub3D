/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:00:58 by babkar            #+#    #+#             */
/*   Updated: 2023/01/25 13:44:56 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include "../srcs/utils/utils.h"
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
	int			nbr_colums;
	int			nbr_lines;
	char		**map;
}t_game;

int		render(t_game *map);
t_game	textures_init(t_game game);
t_game	ray_init(t_game	map);
t_game	initialize_struct(void);

void	check_map(char **str, t_game *game);
void	check_ext(char *av);
int		check_spaces(char **str);
int		check_space(char **str);
int		check_extension(char *str);
t_game	check_indentifiers(int fd, t_game game, char *line);
int		skip_inner_spaces1(char **str, int i, int j);
int		skip_inner_spaces(char **str, int i, int j);
int		skip_backward_spaces(char **str, int i);
int		skip_first_spaces(char **str, int i);
int		check_characters(char **str);
int		ft_check_player(char **str);
int		parse_n_texture(char *texture, t_game *game);
int		parse_s_texture(char *texture, t_game *game);
int		parse_w_texture(char *texture, t_game *game);
int		parse_e_texture(char *texture, t_game *game);
t_game	parse_identifiers(int fd, t_game game);
char	**read_map(char *line, char **map);
void	check_line(char *line, t_game *game);
t_game	*parse_map(char **map_str, t_game *game);
int		parse_color_floor(char *color, t_color *floor);
int		parse_color_ceiling(char *color, t_color *ceiling);
t_game	parse(char **argv, t_game game);
int		count_splited(char **str);
int		count_char(char *str, char c);
char	*skip_empty_line(int fd);
int		empty_line(char *line);
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