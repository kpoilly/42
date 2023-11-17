/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:33:53 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/17 17:54:23 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char **next_line, int pos)
{
	char	*line;
	char	*temp;

	line = ft_strndup(*next_line, pos + 1);
	temp = ft_strndup(*next_line + pos + 1,
			ft_strlen(*next_line + pos + 1));
	free(*next_line);
	*next_line = ft_strndup(temp, -1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*buffer;
	int			checker;
	int			reader;

	checker = isnewline(next_line, '\n');
	if (checker >= 0)
		return (get_line(&next_line, checker));
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	reader = read(fd, buffer, BUFFER_SIZE);
	if (reader == -1)
		return (NULL);
	next_line = ft_strjoin(next_line, buffer);
	checker = isnewline(next_line, '\n');
	while (checker == -1 && reader && reader != -1)
	{
		ft_bzero(buffer, ft_strlen(buffer));
		reader = read(fd, buffer, BUFFER_SIZE);
		next_line = ft_strjoin(next_line, buffer);
		checker = isnewline(next_line, '\n');
	}
	if (checker >= 0)
		return (get_line(&next_line, checker));
	if (!reader)
		return (end_of_file(&next_line));
	return (NULL);
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
