/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:00:58 by babkar            #+#    #+#             */
/*   Updated: 2023/01/19 02:36:29 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cub3D_H
# define cub3D_H

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include "../utils/utils.h"
# include <math.h>

# define ESC_KEY 53
# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2
# define LEFT_ARROW_KEY 124
# define RIGHT_ARROW_KEY 123
# define GRID_SIZE 64
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 720
# define WALL_STRIP_WIDTH 1



typedef struct s_color
{
	int red;
	int green;
	int blue;
	int	trgb;
}t_color;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}t_mlx;

typedef	struct s_ray
{
	double		begin_x;
	double		begin_y;
	double		end_x;
	double		end_y;
	double		horizontal_intersection_x;
	double		horizontal_intersection_y;
	double		vertical_intersection_x;
	double		vertical_intersection_y;
	double		vertical_distance;
	double		horizontal_distance;
	int			nbr_rays;
	double		ray_angle_speed;
	double		ray_angle;
}t_ray;

typedef	struct s_player
{
	double	x;
	double y;
	char	view;
	double	field_of_view;
	int		move_horizontaly;
	int		move_verticaly;
	int		rotate;
	double	rotation_angle;
	double 	move_speed;
	double	rotation_speed;
}t_player;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		*addr_int;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		size;
	
}				t_img;

typedef struct s_map
{
	char	*north_texture_xpm;
	char	*south_texture_xpm;
	char	*west_texture_xpm;
	char	*east_texture_xpm;
	t_img	north_texture;
	t_img	south_texture;
	t_img	west_texture;
	t_img	east_texture;
	t_ray	ray;
	t_color	floor;
	t_color	ceiling;
	t_mlx	mlx;
	t_player player;
	t_img	img;
	int		nbr_colums;
	int		nbr_lines;
	char	**map;
}t_map;

int		render(t_map *map);

t_map   *casting_rays(t_map *map);
t_map   textures_init(t_map map);

void check_map(char **str, t_map *map);
void check_ext(char *av);
int check_spaces(char **str);
int check_space(char **str); 
int skip_inner_spaces1(char **str, int i, int j);
int skip_inner_spaces(char **str, int i, int j);
int skip_backward_spaces(char **str, int i);
int skip_first_spaces(char **str, int i);

int		check_characters(char **str);
int 	ft_check_player(char **str);

int	    parse_north_texture(char *texture, t_map *map);
int	    parse_south_texture(char *texture, t_map *map);
int	    parse_west_texture(char *texture, t_map *map);
int	    parse_east_texture(char *texture, t_map *map);
t_map	parse_identifiers(char *line, int fd, t_map map);


char	**read_map(char *line, char **map);
void	check_line(char *line, t_map *map);
t_map	*parse_map(char **map_str, t_map *map);

int	    parse_color_floor(char *color, t_color *floor);
int	    parse_color_ceiling(char *color, t_color *ceiling);

int	    count_splited(char **str);
int     count_char(char *str, char c);
char    *skip_empty_line(int fd);
int	    empty_line(char *line);

t_map	parse(char **argv);

void	draw_line(t_map map, double beginX, double beginY, double endX, double endY, int color);
void	bresenham(t_map map, double x0, double y0, double x1, double y1, double c);

void	print_map(t_map map);
t_map	player_init(t_map  map);
void	ft_window(t_mlx *mlx, t_map map);
t_map	*render_mini_map(t_map *map);
void    draw_line(t_map map, double beginX, double beginY, double endX, double endY, int color);
void    draw_square(t_map map, double i, double j, int color);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
t_map	*update_player_position(t_map *map);
double  normalizeAngle(double angle);


t_map   *render_walls(t_map *map);

t_map   *casting_rays(t_map *map);
t_map   *cast_ray(t_map *map, double ray_angle);

int	create_trgb(int t, int r, int g, int b);
#endif