/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:33:43 by babkar            #+#    #+#             */
/*   Updated: 2021/11/17 10:31:11 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	size_t			j;
	unsigned char	*string1;
	unsigned char	*string2;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	j = 0;
	i = 0;
	while (i < n)
	{
		if (string1[i] != string2[j])
			return (string1[i] - string2[j]);
		if (string1[i] == '\0' && string2[j] == '\0')
			return (0);
		i++;
		j++;
	}
	return (0);
}
