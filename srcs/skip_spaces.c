/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_spaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:30:17 by bmaaqoul          #+#    #+#             */
/*   Updated: 2023/01/12 18:49:16 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int skip_first_spaces(char **str, int i)
{
	int	j;

	j = 0;
	while (str[i][j] && str[i][j] == '2')
		j++;
	if (str[i][j] != '1')
		return (0);
	return (1);
}

int skip_backward_spaces(char **str, int i)
{
	int	j;

	j = ft_strlen(str[i]) - 1;
	while (str[i][j] && str[i][j] == '2')
		j--;
	if (str[i][j] != '1')
		return (0);
	return (1);
}

int skip_inner_spaces(char **str, int i, int j)
{
	while (str[i] && str[i][j] == '2')
		i++;
	if (str[i] && str[i][j] != '1')
		return (0);
	return (1);
}

int skip_inner_spaces1(char **str, int i, int j)
{
	while (str[i] && str[i][j] == '2')
		i--;
	if (str[i] && str[i][j] != '1')
		return (0);
	return (1);
}

int check_space(char **str)
{
    int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '2' && i > 0)
			{
				if (str[i][j + 1] == '0')
					return (0);
				if (str[i][j - 1] == '0')
					return (0);
				if (str[i + 1] && str[i + 1][j] == '0')
					return (0);
				if (str[i - 1] && str[i - 1][j] == '0')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}