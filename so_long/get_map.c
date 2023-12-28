/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:08:51 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/28 21:16:37 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

static int	maplen(char *filename)
{
	char	*str;
	int		fd;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		i++;
		str = get_next_line(fd);
	}
	close (fd);
	return (i);
}

//Recupere la map dans un fichier .ber et la met dans un char**
char	**get_map(char *filename, int *nb_line, int *nb_col)
{
	int		fd;
	int		i;
	char	**map;

	i = maplen(filename);
	if (!i)
		return (NULL);
	map = malloc((i + 1) * sizeof(char *));
	*nb_line = i;
	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map[i] = get_next_line(fd);
	while (map[i] != NULL)
		map[++i] = get_next_line(fd);
	*nb_col = ft_strlen(map[0]);
	close(fd);
	return (map);
}
