/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:41:03 by bmaaqoul          #+#    #+#             */
/*   Updated: 2023/01/28 20:24:03 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_check_player(char **str)
{
	int	i;
	int	j;
	int	p;

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
	int	i;
	int	j;

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

void	check_map_extension(char *av)
{
	int	len;

	len = ft_strlen(av);
	if (av[len - 1] != 'b' || av[len - 2] != 'u'
		|| av[len - 3] != 'c' || av[len - 4] != '.')
		puterr("wrong extension\n");
}
