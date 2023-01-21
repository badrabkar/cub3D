/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:54:14 by babkar            #+#    #+#             */
/*   Updated: 2023/01/17 15:57:55 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_map	parse(char **argv)
{
	int		fd;
	char	*line;
	t_map	map = {.map = NULL};
	char	**map_str;
	
	line = NULL;
	map_str = NULL;
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
		puterr("fd error\n");
	map = parse_identifiers(line, fd, map);
	line = skip_empty_line(fd);
	if (!line)
		puterr("map order reversed\n");
	while(line)
	{
		map.nbr_lines++;
		if (empty_line(line))
            puterr("empty line\n");
		map_str = read_map(line, map_str);
		line = get_next_line(fd);
	}
	check_map(map_str, &map);
	ft_free(map_str);
	close(fd);
	return (map);
}
