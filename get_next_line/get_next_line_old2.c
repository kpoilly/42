/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_old2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:48:53 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/16 19:35:05 by kpoilly          ###   ########.fr       */
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

char	*get_line(char *buffer, int n)
{
	char	*str;

	if (!buffer)
		return (NULL);
	str = malloc((n + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, buffer, (n + 1));
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*temp;
	int			reader;
	char		*buffer;
	int			checker;

	checker = isnewline(next_line, '\n');
	if (checker >= 0)
	{
		buffer = get_line(next_line, checker);
		if (!buffer)
			return (NULL);
		next_line = ft_strdup(ft_strchr(buffer, '\n'));
		return (buffer);
	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	reader = read(fd, &buffer, BUFFER_SIZE);
	printf("buffer: %s\n", buffer);
	if (reader == -1)
		return (NULL);
	checker = isnewline(buffer, '\n');
	if (checker >= 0)
	{
		temp = ft_strjoin();
		next_line = ft_strdup(ft_strchr(buffer, '\n'));
		
		return (get_line(buffer, checker));
	}
	while (reader && reader != -1 && checker < 0)
	{
		reader = read(fd, &buffer, BUFFER_SIZE);
		checker = isnewline(buffer, '\n');
	}
	if (checker >= 0)
	{
		next_line = ft_strdup(ft_strchr(buffer, '\n'));
		return (get_line(buffer, checker));
	}
	return (get_line(buffer, ft_strlen(buffer)));
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
