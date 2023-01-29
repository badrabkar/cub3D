/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:53:38 by babkar            #+#    #+#             */
/*   Updated: 2023/01/29 01:22:26 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	parse_n_texture(char *texture, t_game *game)
{
	int			i;
	static int	done;
	int			fd;

	i = 2;
	if (done == 1)
		puterr("The n texture is defined!\n");
	while (texture[i] && texture[i] == ' ')
		i++;
	texture = ft_substr(texture, i + 2, ft_strlen(texture));
	if (!check_texture_extension(texture))
		puterr("Check the Extension please!\n");
	game->n_texture_xpm = texture;
	fd = open(texture, O_RDONLY);
	if (fd == -1)
		puterr("File not found!");
	close(fd);
	done = 1;
	return (1);
}

int	parse_s_texture(char *texture, t_game *game)
{
	int			i;
	static int	done;
	int			fd;

	i = 2;
	if (done == 1)
		puterr("The s texture is defined!\n");
	while (texture[i] && texture[i] == ' ')
		i++;
	texture = ft_substr(texture, i + 2, ft_strlen(texture));
	if (!check_texture_extension(texture))
		puterr("Check the Extension please!\n");
	game->s_texture_xpm = texture;
	fd = open(texture, O_RDONLY);
	if (fd == -1)
		puterr("File not found!");
	close(fd);
	done = 1;
	return (1);
}

int	parse_w_texture(char *texture, t_game *game)
{
	int			i;
	static int	done;
	int			fd;

	i = 2;
	if (done == 1)
		puterr("The w texture is defined!\n");
	while (texture[i] && texture[i] == ' ')
		i++;
	texture = ft_substr(texture, i + 2, ft_strlen(texture));
	if (!check_texture_extension(texture))
		puterr("Check the Extension please!\n");
	game->w_texture_xpm = texture;
	fd = open(texture, O_RDONLY);
	if (fd == -1)
		puterr("File not found!");
	close(fd);
	done = 1;
	return (1);
}

int	parse_e_texture(char *texture, t_game *game)
{
	int			i;
	static int	done;
	int			fd;

	i = 2;
	if (done == 1)
		puterr("The e texture is defined!\n");
	while (texture[i] && texture[i] == ' ')
		i++;
	texture = ft_substr(texture, i + 2, ft_strlen(texture));
	if (!check_texture_extension(texture))
		puterr("Check the Extension please!\n");
	game->e_texture_xpm = texture;
	fd = open(texture, O_RDONLY);
	if (fd == -1)
		puterr("File not found!");
	close(fd);
	done = 1;
	return (1);
}

t_game	get_counter(t_game game, int *counter, char *line)
{
	if (line[0] == 'F' && line[1] == ' ')
		*counter += parse_color_floor(line, &game.floor);
	else if (line[0] == 'C' && line[1] == ' ')
		*counter += parse_color_ceiling(line, &game.ceiling);
	else if (line[0] == 'N' && line[1] == 'O'
		&& line[2] == ' ')
		*counter += parse_n_texture(line, &game);
	else if (line[0] == 'S' && line[1] == 'O'
		&& line[2] == ' ')
		*counter += parse_s_texture(line, &game);
	else if (line[0] == 'W' && line[1] == 'E'
		&& line[2] == ' ')
		*counter += parse_w_texture(line, &game);
	else if (line[0] == 'E' && line[1] == 'A'
		&& line[2] == ' ')
		*counter += parse_e_texture(line, &game);
	else if (!empty_line(line))
		puterr("something wrong in indentifiers!\n");
	return (game);
}
