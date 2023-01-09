/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 01:25:02 by babkar            #+#    #+#             */
/*   Updated: 2023/01/03 12:55:48 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
char	**ft_realloc(char **str, int size)
{
    char **new_str;
	int		i;
	
	i = 0;
	if (str == NULL)
		return (char **)malloc((size + 1) * sizeof(char *));
	if (size == 0)
		return NULL;
	new_str = (char **)malloc((size + 1) * sizeof(char *));
	if (!new_str)
		exit(1);
	while (i < size)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[size] = NULL;
	return (new_str);
}
