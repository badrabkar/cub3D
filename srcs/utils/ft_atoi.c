/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 09:08:03 by babkar            #+#    #+#             */
/*   Updated: 2023/01/24 00:21:43 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 45)
		sign *= (-1);
	if (*str == 45 || *str == 43)
		str++;
	if (!ft_isdigit(*str))
		return (0);
	while (ft_isdigit(*str))
		num = num * 10 + (*str++ - 48);
	return (num * sign);
}
