/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:54:14 by babkar            #+#    #+#             */
/*   Updated: 2023/01/29 01:51:53 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_game	parse_identifiers(t_game game)
{
	int		counter;
	int		i;
	char	*line;

	counter = 0;
	game.parse.line = get_next_line(game.parse.fd);
	while (game.parse.line && counter != 6)
	{
		i = 0;
		while (game.parse.line[i] && game.parse.line[i] == ' ')
			i++;
		check_tabs(game.parse.line);
		line = ft_substr(game.parse.line, i, ft_strlen(game.parse.line));
		game = get_counter(game, &counter, line);
		free(game.parse.line);
		free(line);
		game.parse.line = get_next_line(game.parse.fd);
	}
	if (counter != 6)
		puterr("An identifier is missing!\n");
	if (game.floor.trgb == game.ceiling.trgb)
		puterr("Floor and ceiling have the same color!\n");
	return (game);
}

t_game	parse(char **argv, t_game game)
{
	game.parse.map_str = NULL;
	game.parse.fd = open(argv[1], O_RDWR);
	if (game.parse.fd == -1)
		puterr("fd error\n");
	game = parse_identifiers(game);
	game = skip_empty_line(game);
	if (!game.parse.line)
		puterr("map order reversed\n");
	while (game.parse.line)
	{
		game.nbr_lines++;
		check_tabs(game.parse.line);
		if (empty_line(game.parse.line))
			puterr("empty line\n");
		game = read_map(game);
		free (game.parse.line);
		game.parse.line = get_next_line(game.parse.fd);
	}
	check_map(game.parse.map_str, &game);
	close(game.parse.fd);
	return (game);
}
