/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:44:34 by bmaaqoul          #+#    #+#             */
/*   Updated: 2023/01/09 16:01:42 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_walls(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '0')
			return (0);
		i++;
	}
	return (1);
}

int check_spaces(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!skip_first_spaces(str, i) || !skip_backward_spaces(str, i))
			return (0);
		i++;
	}
	return (1);
}

void check(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!check_spaces(str) || !check_space(str))
		puterr();
	while (str[i])
		i++;
	i--;
	while (str[i][j])
	{
		if (!skip_inner_spaces1(str, i, j))
			puterr();
		j++;
	}
	if (!ft_check_player(str) || !check_characters(str))
		puterr();
	if (!check_walls(str[0]) || !check_walls(str[i]))
		puterr();
	j = 0;
	i = 0;
	while (str[i][j])
	{
		if (!skip_inner_spaces(str, i, j))
			puterr();
		j++;
	}
}

int ft_check_player(char **str)
{
	int i;
	int j;
	int p;

	i = 0;
	p = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'N' || str[i][j] == 'S'
				|| str[i][j] == 'W' || str[i][j] == 'E')
				p++;
			j++;
		}
		i++;
	}
	if (p != 1)
		return (0);
	return (1);
}

int	check_characters(char **str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] != 'N' && str[i][j] != 'S' && str[i][j] != 'W'
				&& str[i][j] != 'E' && str[i][j] != '1'
					&& str[i][j] != '0' && str[i][j] != '2')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void check_ext(char *av)
{
	int len;

	len = ft_strlen(av);
	if (av[len - 1] != 'b' || av[len - 2] != 'u'
		|| av[len - 3] != 'c' || av[len - 4] != '.')
		puterr();
}

void check_map(char **str, t_map *map)
{
	map = parse_map(str, map);
	check(map->map);
}
