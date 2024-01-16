/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:33:53 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/16 11:24:12 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *next_line, int *pos)
{
	char	*line;

	if (!*next_line)
		return (NULL);
	if (*pos < 0)
		*pos = ft_strlen(next_line) - 1;
	line = ft_strndup(next_line, *pos + 1);
	if (!line)
		return (NULL);
	return (line);
}

char	*get_next(char *next_line, int pos)
{
	char	*next;

	if (!*(next_line + pos + 1))
	{
		free(next_line);
		return (NULL);
	}
	next = ft_strndup(next_line + pos + 1, -1);
	if (!next)
		return (NULL);
	free(next_line);
	return (next);
}

char	*file_reader(int fd, char *next_line, int *checker)
{
	int		reader;
	char	*buffer;
	char	*temp;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	reader = 1;
	*checker = isnewline(next_line);
	while (*checker == -1 && reader && reader != -1)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		buffer[reader] = '\0';
		temp = ft_strjoin(next_line, buffer);
		free(next_line);
		next_line = ft_strndup(temp, -1);
		free(temp);
		*checker = isnewline(next_line);
	}
	free(buffer);
	if (*checker >= 0 || !reader)
		return (next_line);
	free(next_line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*next_line = NULL;
	char		*line;
	int			checker;

	if (fd < 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	next_line = file_reader(fd, next_line, &checker);
	if (!next_line)
		return (NULL);
	line = get_line(next_line, &checker);
	next_line = get_next(next_line, checker);
	return (line);
}

// int	main(int argc, char **argv)
// {
// 	int  fd = open(argv[1], O_RDONLY);
// 	int i = 0;
// 	char *str;

// 	(void)argc;
// 	while (i < atoi(argv[2]))
// 	{
// 		str = get_next_line(fd);
// 		printf("%d: %s", i + 1, str);
// 		free(str);
// 		i++;
// 	}
// 	close(fd);
// }
