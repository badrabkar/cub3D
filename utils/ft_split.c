/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 13:58:11 by babkar            #+#    #+#             */
/*   Updated: 2021/11/16 20:36:34 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

int	wordcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1] == 0) && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

char	**ft_malloc(char const *s, char c)
{
	char	**t;

	t = malloc((wordcount(s, c) + 1) * sizeof(char *));
	if (!t)
		return (0);
	return (t);
}

int	next_word_len(char const *s, char c, int i)
{
	int	count;

	count = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		i++;
		count++;
	}
	return (count);
}

static char	**ft_free_s(char **t, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(t[j++]);
	free(t);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		f;
	int		i;
	int		j;
	char	**t;

	if (s == 0)
		return (0);
	i = 0;
	f = -1;
	t = ft_malloc(s, c);
	if (!t)
		return (0);
	while (++f < wordcount(s, c))
	{
		j = 0;
		t[f] = ft_calloc(next_word_len(s, c, i) + 1, sizeof(char));
		if (!t)
			return (ft_free_s(t, f));
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
			t[f][j++] = s[i++];
	}
	t[f] = 0;
	return (t);
}
