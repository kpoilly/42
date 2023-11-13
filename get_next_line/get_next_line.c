/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:52:50 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/13 17:53:32 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		reader;
	char	buffer;

	reader = read(fd, &buffer, 1);
	if (reader == -1)
		return (NULL);
	while (reader && reader != -1 && buffer != '\n')
	{
		write(1, &buffer, 1);
		reader = read(fd, &buffer, 1);
	}
	return ("test");
}

int	main(int argc, char **argv)
{
	int  fd = open(argv[1], O_RDONLY);
	int i = 0;

	while (i < ft_atoi(argv[2]))
	{
		get_next_line(fd);
		write(1, "\n", 1);
		i++;
	}
	close(fd);
}
