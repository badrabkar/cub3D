/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:44:34 by bmaaqoul          #+#    #+#             */
/*   Updated: 2023/01/28 19:38:09 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_walls(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			return (0);
		i++;
	}
	return (1);
}

int	check_spaces(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!skip_first_spaces(str, i) || !skip_backward_spaces(str, i))
			return (0);
		i++;
	}
	return (1);
}

void	check(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	if (!check_spaces(str) || !check_space(str))
		puterr("enter a valid map!\n");
	while (str[i])
		i++;
	i--;
	while (str[i][++j])
		if (!skip_inner_spaces1(str, i, j))
			puterr("enter a valid map!\n");
	if (!ft_check_player(str) || !check_characters(str))
		puterr("enter the valid characters!\n");
	if (!check_walls(str[0]) || !check_walls(str[i]))
		puterr("map not enclosed\n");
	j = -1;
	i = 0;
	while (str[i][++j])
		if (!skip_inner_spaces(str, i, j))
			puterr("enter a valid map!\n");
}

void	check_map(char **str, t_game *game)
{
	game = parse_map(str, game);
	check(game->map);
}
