/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:52:15 by babkar            #+#    #+#             */
/*   Updated: 2023/01/12 17:20:23 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	count_splited(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int count_char(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

char *skip_empty_line(char *line, int fd)
{
	line = get_next_line(fd);
	while(line)
	{
		if (!empty_line(line))
			break;
		free (line);
		line = get_next_line(fd);
		if (!line)
            break;
	}
    return (line);
}

int	empty_line(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '\n')
		return (1);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

