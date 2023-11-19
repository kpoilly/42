/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:33:53 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/19 17:24:42 by kpoilly          ###   ########.fr       */
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

t_monoread	*seek_fd(int fd, t_monoread *current)
{
	if (!current)
	{
		current = malloc(sizeof(t_monoread));
		current->fd = fd;
		current->str = NULL;
		current->next = NULL;
	}
	else if (current->fd != fd)
		seek_fd(fd, current->next);
	return (current);
}

char	*get_next_line(int fd)
{
	static t_monoread	*current = NULL;
	char				*buffer;
	char				*temp;
	int					checker;
	int					reader;

	current = seek_fd(fd, current);
	if (fd < 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	checker = isnewline(current->str, '\n');
	if (checker >= 0)
		return (get_line(&(current->str), checker));
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	reader = read(fd, buffer, BUFFER_SIZE);
	buffer[reader] = 0;
	if (!current->str)
		current->str = ft_strndup("", -1);
	temp = ft_strjoin(current->str, buffer);
	free(current->str);
	current->str = ft_strndup(temp, -1);
	free(temp);
	return (file_reader(fd, reader, buffer, &(current->str)));
}

/* int	main(int argc, char **argv)
{
	int  fd = open(argv[1], O_RDONLY);
	int i = 0;

	(void)argc;
	while (i < ft_atoi(argv[2]))
	{
		printf("%d: %s", i + 1, get_next_line(fd));
		i++;
	}
	close(fd);
} */
