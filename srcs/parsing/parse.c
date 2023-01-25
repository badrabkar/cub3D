/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:54:14 by babkar            #+#    #+#             */
/*   Updated: 2023/01/25 11:44:42 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_game	parse_identifiers(int fd, t_game game)
{
	char	*line;

	line = get_next_line(fd);
	game = check_indentifiers(fd, game, line);
	if (game.floor.trgb == game.ceiling.trgb)
		puterr("Floor and ceiling have the same color!\n");
	return (game);
}

t_game	parse(char **argv, t_game game)
{
	int		fd;
	char	*line;
	char	**map_str;

	map_str = NULL;
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
		puterr("fd error\n");
	game = parse_identifiers(fd, game);
	line = skip_empty_line(fd);
	if (!line)
		puterr("map order reversed\n");
	while (line)
	{
		game.nbr_lines++;
		if (empty_line(line))
			puterr("empty line\n");
		map_str = read_map(line, map_str);
		line = get_next_line(fd);
	}
	check_map(map_str, &game);
	ft_free(map_str);
	close(fd);
	return (game);
}
