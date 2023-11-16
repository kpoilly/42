/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:33:53 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/16 23:12:45 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	isnewline(char *str, char c)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*buffer;
	int			checker;
	int			reader;

	checker = isnewline(next_line, '\n');
	if (checker >= 0)
	{
		buffer = ft_strndup(ft_strchr(next_line, '\n'), -1);
		next_line += checker;
		return (buffer);
	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	reader = read(fd, buffer, BUFFER_SIZE);
	if (reader == -1)
		return (NULL);
	checker = isnewline(next_line, '\n');
	while (checker == -1 && reader && reader != -1)
	{
		next_line = ft_strjoin(next_line, buffer);
		reader = read(fd, buffer, BUFFER_SIZE);
		checker = isnewline(next_line, '\n');
	}
	if (checker >= 0)
	{
		buffer = ft_strndup(next_line, checker + 1);
		next_line = ft_strndup(ft_strchr(next_line, '\n'), -1);
		return (buffer);
	}
	if (!reader)
	{
		return (next_line);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	int  fd = open(argv[1], O_RDONLY);
	int i = 0;

	(void)argc;
	while (i < ft_atoi(argv[2]))
	{
		printf("%d: ", i + 1);
		printf("%s", get_next_line(fd));
		i++;
	}
	close(fd);
}
