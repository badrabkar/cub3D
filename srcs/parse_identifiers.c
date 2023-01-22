/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:53:38 by babkar            #+#    #+#             */
/*   Updated: 2023/01/21 16:27:19 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	count_point(char *str)
{
	int	i;
	int	cp;

	cp = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			cp++;
		i++;
	}
	if (!cp || cp != 1)
		return (0);
	return (1);
}

int	check_extension(char *str)
{
	char	*s;
	size_t		i;

	i = ft_strlen(str) - 4;
	s = ".xpm";
	if (count_point(str))
	{
		if (!ft_strncmp(str + i, s, 4))
			return (1);
	}
	return (0);
}

int	parse_north_texture(char *texture, t_map *map)
{
	int	i;
	static int	done;
	int	fd;
	
	if (done == 1)
		puterr("The north texture is defined!\n");
	i = 2;
	while (texture[i] && texture[i] == ' ')
		i++;
	texture = ft_substr(texture, i + 2, ft_strlen(texture));
	if (!check_extension(texture))
		puterr("Check the Extension please!\n");
	map->north_texture_xpm = texture;
	fd = open(texture, O_RDONLY);
	if (fd == -1)
		puterr("File not found!");
	close(fd);
	done = 1;
	return (1);
}

int	parse_south_texture(char *texture, t_map *map)
{
	int	i;
	static int	done;
	int			fd;

	if (done == 1)
		puterr("The south texture is defined!\n");
	i = 2;
	while (texture[i] && texture[i] == ' ')
		i++;
	texture = ft_substr(texture, i + 2, ft_strlen(texture));
	if (!check_extension(texture))
		puterr("Check the Extension please!\n");
	map->south_texture_xpm = texture;
	fd = open(texture, O_RDONLY);
	if (fd == -1)
		puterr("File not found!");
	close(fd);
	done = 1;
	return (1);
}

int	parse_west_texture(char *texture, t_map *map)
{
	int	i;
	static int	done;
	int			fd;

	if (done == 1)
		puterr("The west texture is defined!\n");
	i = 2;
	while (texture[i] && texture[i] == ' ')
		i++;
	texture = ft_substr(texture, i + 2, ft_strlen(texture));
	if (!check_extension(texture))
		puterr("Check the Extension please!\n");
	map->west_texture_xpm = texture;
	fd = open(texture, O_RDONLY);
	if (fd == -1)
		puterr("File not found!");
	close(fd);
	done = 1;
	return (1);
}

int	parse_east_texture(char *texture, t_map *map)
{
	int	i;
	static int	done;
	int			fd;
	
	if (done == 1)
		puterr("The east texture is defined!\n");
	i = 2;
	while (texture[i] && texture[i] == ' ')
		i++;
	texture = ft_substr(texture, i + 2, ft_strlen(texture));
	if (!check_extension(texture))
		puterr("Check the Extension please!\n");
	map->east_texture_xpm = texture;
	fd = open(texture, O_RDONLY);
	if (fd == -1)
		puterr("File not found!");
	close(fd);
	done = 1;
	return (1);
}

t_map	parse_identifiers(char *line, int fd, t_map map)
{
	int counter;
	
	counter = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == 'F' && line[1] == ' ')
			counter += parse_color_floor(line, &map.floor);
		else if (line[0] == 'C' && line[1] == ' ')
			counter += parse_color_ceiling(line, &map.ceiling);
		else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
			counter += parse_north_texture(line, &map);
		else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
			counter += parse_south_texture(line, &map);
		else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
			counter += parse_west_texture(line, &map);
		else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
			counter += parse_east_texture(line, &map);
		if (counter == 6)
			break;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (counter != 6)
		puterr("check the map again please\n");
	if (map.floor.trgb == map.ceiling.trgb)
		puterr("Floor and ceiling have the same color!\n");
	return (map);
}