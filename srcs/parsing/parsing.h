/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:32:15 by babkar            #+#    #+#             */
/*   Updated: 2023/01/29 01:21:42 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_game	t_game;

int		ft_check_player(char **str);
int		check_characters(char **str);
void	check_map_extension(char *av);

int		check_walls(char *str);
int		check_spaces(char **str);
int		check_space(char **str);
void	check(char **str);
void	check_map(char **str, t_game *game);
t_game	get_counter(t_game game, int *counter, char *line);

int		check_texture_extension(char *str);
t_game	check_indentifiers(t_game game);
int		skip_inner_spaces1(char **str, int i, int j);
int		skip_inner_spaces(char **str, int i, int j);
int		skip_backward_spaces(char **str, int i);
int		skip_first_spaces(char **str, int i);
int		check_characters(char **str);
int		ft_check_player(char **str);
t_game	read_map(t_game game);
void	check_line(char *line, t_game *game);
t_game	*parse_map(char **map_str, t_game *game);
int		parse_color_floor(char *color, t_color *floor);
int		parse_color_ceiling(char *color, t_color *ceiling);
t_game	parse(char **argv, t_game game);
int		count_splited(char **str);
int		count_char(char *str, char c);
t_game	skip_empty_line(t_game game);
int		empty_line(char *line);
#endif