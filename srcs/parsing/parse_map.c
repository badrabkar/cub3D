/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 05:01:20 by babkar            #+#    #+#             */
/*   Updated: 2023/01/24 20:08:03 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	**read_map(char *line, char **map)
{
	static int	counter;
	int			i;

	i = 0;
	counter++;
	map = ft_realloc(map, counter);
	if (!map)
		exit(1);
	map[counter - 1] = line;
	return (map);
}

int	get_map_longest_line(char **map_str, t_game *game)
{
	int	i;
	int	longest_line;

	i = 0;
	longest_line = strlen(map_str[0]);
	while (i < game->nbr_lines)
	{
		if ((int)strlen(map_str[i]) > longest_line)
			longest_line = strlen(map_str[i]);
		i++;
	}
	return (longest_line);
}

t_game	*parse_map(char **map_str, t_game *game)
{
	int	i;
	int	f;

	i = 0;
	game->nbr_colums = get_map_longest_line(map_str, game);
	game->map = (char **)calloc(game->nbr_lines + 1, sizeof(char *));
	if (!game->map)
		exit(2);
	while (i < game->nbr_lines)
	{
		game->map[i] = (char *)calloc(game->nbr_colums + 1, sizeof(char));
		if (!game->map[i])
			exit(1);
		f = 0;
		while (f < game->nbr_colums)
		{
			if (map_str[i][f] == ' ' || f > (int)strlen(map_str[i]) - 1)
				game->map[i][f] = '2';
			else
				game->map[i][f] = map_str[i][f];
			f++;
		}
		i++;
	}
	return (game);
}
