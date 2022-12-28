/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_second_identifiers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 05:00:55 by babkar            #+#    #+#             */
/*   Updated: 2022/12/24 05:01:10 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_color_floor(char *color, t_color *floor)
{
	char	**splited;
	static int	done;

	if (done == 1)
		puterr();
	color = ft_substr(color,2,ft_strlen(color));
	splited = ft_split(color,',');
	if (count_splited(splited) != 3)
		puterr();
	if (count_char(color,',') != 2)
		puterr();
	floor->red = ft_atoi(splited[0]);
	if (floor->red < 0 || floor->red > 255)
		puterr();
	floor->green = ft_atoi(splited[1]);
	if (floor->green < 0 || floor->green > 255)
		puterr();
	floor->blue =  ft_atoi(splited[2]);
	if (floor->blue < 0 || floor->blue > 255)
		puterr();
	done = 1;
	return (1);
}

int	parse_color_ceiling(char *color, t_color *ceiling)
{
	char	**splited;
	static int	done;

	if (done == 1)
		puterr();
	color = ft_substr(color,2,ft_strlen(color));
	splited = ft_split(color,',');
	if (count_splited(splited) != 3)
		puterr();
	if (count_char(color,',') != 2)
		puterr();
	ceiling->red = ft_atoi(splited[0]);
	if (ceiling->red < 0 || ceiling->red > 255)
		puterr();
	ceiling->green = ft_atoi(splited[1]);
	if (ceiling->green < 0 || ceiling->green > 255)
		puterr();
	ceiling->blue =  ft_atoi(splited[2]);
	if (ceiling->red < 0 || ceiling->red > 255)
		puterr();
	done = 1;
	return (1);
}