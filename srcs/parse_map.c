/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 05:01:20 by babkar            #+#    #+#             */
/*   Updated: 2023/01/12 15:09:59 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**read_map(char *line, char **map)
{
	static	int counter;
    int         i;

    i = 0;
	counter++;
	map = ft_realloc(map, counter);
    if (!map)
        exit(1);
    map[counter - 1] = line;
	return (map);
}

void	parse_map(char **map_str, t_map *map)
{
	int	i;
	int	longest_line;
	
	i = 0;
	longest_line = strlen(map_str[0]);
	while (i < map->nbr_lines)
	{
		if ((int)strlen(map_str[i]) > longest_line)
			longest_line = strlen(map_str[i]);
		i++;
	}
	map->nbr_colums = longest_line;
	i = 0;
	map->map = (char ** )calloc(map->nbr_lines + 1, sizeof(char *));
	if (!map->map)
		exit(2);
	while (i < map->nbr_lines)
	{
		map->map[i] = (char *)calloc(longest_line + 1, sizeof(char));
		if (!map->map[i])
			exit(1);
		for (int f = 0; f < longest_line; f++)
		{
			if (map_str[i][f] == ' ' || f > (int)strlen(map_str[i]) - 1)
				map->map[i][f] = '2';
			else
				map->map[i][f] = map_str[i][f];
		}
		i++;
	}
	// return (map);
}