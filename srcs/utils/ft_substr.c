/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:30:41 by babkar            #+#    #+#             */
/*   Updated: 2023/01/28 23:38:03 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*string;
	char	*substring;
	size_t	j;
	size_t	finish;

	if (s)
	{
		string = (char *)s;
		substring = (char *)ft_calloc((len + 1), sizeof(char));
		if (substring == NULL)
			return (0);
		j = 0;
		finish = len + start;
		if (start <= ft_strlen(string))
		{
			while (start < finish && string[start])
				substring[j++] = string[start++];
		}
		return (substring);
	}
	else
		return (NULL);
}
