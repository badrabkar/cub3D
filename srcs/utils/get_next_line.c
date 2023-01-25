/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babkar <babkar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 05:06:12 by babkar            #+#    #+#             */
/*   Updated: 2023/01/24 00:24:16 by babkar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*readline(int fd, char *readline)
{
	char	*buff;
	int		line;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	line = 1;
	while (!ft_strchr(readline, '\n') && line > 0)
	{
		line = read(fd, buff, BUFFER_SIZE);
		if (line == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[line] = '\0';
		readline = ft_strjoin_gnl(readline, buff);
	}
	free (buff);
	return (readline);
}

char	*get_line(char *read)
{
	char	*line;
	int		i;

	i = 0;
	if (read[0] == '\0')
		return (NULL);
	while (read[i] && read[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (read[i] && read[i] != '\n')
	{
		line[i] = read[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*resetread(char *read)
{
	char	*resetread;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (read[i] && read[i] != '\n')
		i++;
	if (read[i] == '\0')
	{
		free(read);
		return (NULL);
	}
	i++;
	resetread = (char *)malloc((ft_strlen(read) - i + 1) * sizeof(char));
	if (!resetread)
		return (NULL);
	while (read[i])
		resetread[j++] = read[i++];
	if (read[i] == '\n')
		resetread[j] = '\n';
	resetread[j] = '\0';
	free (read);
	return (resetread);
}

char	*get_next_line(int fd)
{
	static char	*read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read = readline(fd, read);
	if (!read)
		return (NULL);
	line = get_line(read);
	read = resetread(read);
	return (line);
}
