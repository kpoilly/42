/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:08:51 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/17 14:19:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

//Recupere la map dans un fichier .ber et la met dans un char**
char	**get_map(char *filename, int *nb_line, int *nb_col)
{
	int		fd;
	int		i;
	char	**map;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (get_next_line(fd))
		i++;
	close (fd);
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
