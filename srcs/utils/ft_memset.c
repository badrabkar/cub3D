/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:11:18 by babkar            #+#    #+#             */
/*   Updated: 2021/11/19 09:44:25 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*string;

	string = (unsigned char *)b;
	while (len-- > 0)
		*string++ = (unsigned char)c;
	return (b);
}
