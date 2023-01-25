/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_between_two_points.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:16:37 by babkar            #+#    #+#             */
/*   Updated: 2023/01/24 00:21:12 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

double	dist_between_two_points(double a_x, double a_y, double b_x, double b_y)
{
	return (sqrt(pow(b_x - a_x, 2) + pow(b_y - a_y, 2)));
}
