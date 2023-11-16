/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_old.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:52:50 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/16 20:29:36 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		reader;
	char	*buffer;
	char	*start;
	char	*append;

	buffer = malloc(sizeof(char));
	reader = read(fd, &buffer, 1);
	if (reader == -1)
		return (NULL);
	while (buffer == '\n')
		reader = read(fd, &buffer, 1);
	while (reader && reader != -1 && buffer != '\n')
	{
		start = ft_strjoin(append, &buffer);
		append = ft_strdup(start);
		free(start);
		reader = read(fd, &buffer, 1);
	}
	buffer = '\n';
	start = ft_strjoin(append, &buffer);
	free(append);
	return (start);
}

int	main(int argc, char **argv)
{
	int  fd = open(argv[1], O_RDONLY);
	int i = 0;

	(void)argc;
	while (i < ft_atoi(argv[2]))
	{
		printf("%s", get_next_line(fd));
		i++;
	}
	close(fd);
}
