/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 05:01:20 by babkar            #+#    #+#             */
/*   Updated: 2022/12/31 22:55:50 by babkar           ###   ########.fr       */
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

void	check_top_map(t_map *map)
{
	int	i = 0;
	int	j = ft_strlen(map->map[0]) - 1;
	
	while(map->map[0][i] && map->map[0][i] == ' ')
		i++;
	while (j > 0 && map->map[0][j] == ' ')
		j--;
	if (map->map[0][i] != '1' || map->map[0][j] != '1')
		puterr();
	while (i <= j)
	{
		if (map->map[0][i] == ' ' && (map->map[0][i - 1] != '1'|| map->map[0][i + 1] != '1' || map->map[1][i] != '1' || map->map[1][i - 1] != '1' || map->map[1][i + 1] != '1'))
			puterr();
		if (map->map[0][i] != '1' && map->map[0][i] != ' ')
			puterr();
		i++;
	}
	
}

void	check_bottom_map(t_map *map)
{
	int	i = 0;
	int	j = ft_strlen(map->map[map->nbr_lines - 1]) - 1;
	
	while(map->map[map->nbr_lines - 1][i] && map->map[map->nbr_lines - 1][i] == ' ')
		i++;
	while (j > 0 && map->map[map->nbr_lines - 1][j] == ' ')
		j--;
	if (map->map[map->nbr_lines - 1][i] != '1' || map->map[map->nbr_lines - 1][j] != '1')
		puterr();
	while (i <= j)
	{
		// if (map->map[map->nbr_lines - 1][i] == ' ' && (map->map[map->nbr_lines - 1][i - 1] != '1'|| map->map[map->nbr_lines - 1][i + 1] != '1' || map->map[map->nbr_lines - 2][i] != '1' || map->map[map->nbr_lines - 2][i - 1] != '1' || map->map[map->nbr_lines - 2][i + 1] != '1'))
		// 	puterr();
		if (map->map[map->nbr_lines - 1][i] != '1' && map->map[map->nbr_lines - 1][i] != ' ')
			puterr();
		i++;
	}
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
	i = 0;
	map->map = (char ** )calloc(map->nbr_lines, sizeof(char *));
	if (!map->map)
		exit(2);
	while (i < 14)
	{
		map->map[i] = (char *)calloc(longest_line, sizeof(char));
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
	
	// check_top_map(map);		
	// check_bottom_map(map);		
}

void	check_line(char *line, t_map *map)
{
	int			i;
	static int	player;
	
	i = 0;
	while (line[i])
	{
		if (line[i] == 'W' || line[i] == 'S' || line[i] == 'E' || line[i] == 'N')
		{
			if (player == 1)
				puterr();
			player = 1;
		}
		else if (line[i] != ' ' && line[i] != '1' && line[i] != '0'
			&& line[i] != 0 && line[i] != '\n')
			puterr();
		i++;
	}
	map->nbr_lines++;
}