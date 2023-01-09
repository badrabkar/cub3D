/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:54:14 by babkar            #+#    #+#             */
/*   Updated: 2023/01/09 15:42:47 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	parse(char **argv)
{
	int		fd;
	char	*line;
	t_map	map = {.east_texture = NULL, .west_texture = NULL, .north_texture = NULL, .south_texture = NULL, .map = NULL};
	char	**map_str;
	
	line = NULL;
	map_str = NULL;
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
	{
		puts("fd error\n");
		exit(1);
	}
	map = parse_identifiers(line, fd, map);
	line = skip_empty_line(fd);
	if (!line)
		puterr();
	while(line)
	{
		map.nbr_lines++;
		if (empty_line(line))
            puterr();
		map_str = read_map(line, map_str);
		line = get_next_line(fd);
	}
	parse_map(map_str, &map);
	return (map);
}
