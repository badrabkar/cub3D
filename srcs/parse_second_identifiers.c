/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_second_identifiers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 05:00:55 by babkar            #+#    #+#             */
/*   Updated: 2023/01/12 14:16:53 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_color_floor(char *color, t_color *floor)
{
	char	**splited;
	static int	done;

	if (done == 1)
		puterr("check the color floor line\n");
	color = ft_substr(color,2,ft_strlen(color));
	splited = ft_split(color,',');
	if (count_splited(splited) != 3)
		puterr("check the color floor line\n");
	if (count_char(color,',') != 2)
		puterr("check the color floor line\n");
	floor->red = ft_atoi(splited[0]);
	if (floor->red < 0 || floor->red > 255)
		puterr("check the color floor line\n");
	floor->green = ft_atoi(splited[1]);
	if (floor->green < 0 || floor->green > 255)
		puterr("check the color floor line\n");
	floor->blue =  ft_atoi(splited[2]);
	if (floor->blue < 0 || floor->blue > 255)
		puterr("check the color floor line\n");
	done = 1;
	ft_free(splited);
	free (color);
	return (1);
}

int	parse_color_ceiling(char *color, t_color *ceiling)
{
	char	**splited;
	static int	done;

	if (done == 1)
		puterr("check the color ceiling line\n");
	color = ft_substr(color,2,ft_strlen(color));
	splited = ft_split(color,',');
	if (count_splited(splited) != 3)
		puterr("check the color ceiling line\n");
	if (count_char(color,',') != 2)
		puterr("check the color ceiling line\n");
	ceiling->red = ft_atoi(splited[0]);
	if (ceiling->red < 0 || ceiling->red > 255)
		puterr("check the color ceiling line\n");
	ceiling->green = ft_atoi(splited[1]);
	if (ceiling->green < 0 || ceiling->green > 255)
		puterr("check the color ceiling line\n");
	ceiling->blue =  ft_atoi(splited[2]);
	if (ceiling->blue < 0 || ceiling->blue > 255)
		puterr("check the color ceiling line\n");
	done = 1;
	ft_free(splited);
	free (color);
	return (1);
}