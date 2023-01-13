/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 01:25:42 by babkar            #+#    #+#             */
/*   Updated: 2023/01/12 22:42:31 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

char	**ft_free(char **tab);
double  distance_between_two_points(double a_x, double a_y, double b_x, double b_y);
void    puterr(char *str);
char	**ft_realloc(char **str, int size);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*get_next_line(int fd);
double  degree_to_radian(int degree);
#endif