/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:33:53 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/23 11:25:36 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char **next_line, int pos)
{
	char	*line;
	char	*temp;

	line = ft_strndup(*next_line, pos + 1);
	temp = ft_strndup(*next_line + pos + 1,
			ft_strlen(*next_line + pos + 1));
	free(*next_line);
	*next_line = ft_strndup(temp, -1);
	free(temp);
	return (line);
}

char	*end_of_file(char **next_line)
{
	char	*lastline;

	if (ft_strlen(*next_line))
	{
		lastline = ft_strndup(*next_line, -1);
		free(*next_line);
		*next_line = NULL;
	}
	else
		lastline = NULL;
	return (lastline);
}

char	*file_reader(int fd, int reader, char *buffer, char **next_line)
{
	int		checker;
	char	*temp;

	checker = isnewline(*next_line, '\n');
	while (checker == -1 && reader && reader != -1)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		reader = read(fd, buffer, BUFFER_SIZE);
		temp = ft_strjoin(*next_line, buffer);
		free(*next_line);
		*next_line = ft_strndup(temp, -1);
		free(temp);
		checker = isnewline(*next_line, '\n');
	}
	free(buffer);
	if (checker >= 0)
		return (get_line(next_line, checker));
	if (!reader)
		return (end_of_file(next_line));
	free(*next_line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*next_line[1024];
	char		*buffer;
	char		*temp;
	int			checker;
	int			reader;

	if (fd < 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	checker = isnewline(next_line[fd], '\n');
	if (checker >= 0)
		return (get_line(&next_line[fd], checker));
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	reader = read(fd, buffer, BUFFER_SIZE);
	buffer[reader] = 0;
	if (!next_line[fd])
		next_line[fd] = ft_strndup("", -1);
	temp = ft_strjoin(next_line[fd], buffer);
	free(next_line[fd]);
	next_line[fd] = ft_strndup(temp, -1);
	free(temp);
	return (file_reader(fd, reader, buffer, &next_line[fd]));
}
