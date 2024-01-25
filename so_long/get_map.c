/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:08:51 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/25 17:56:57 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

//remplace le \n par un \0
static void	replace_nl(char	*str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	str[i] = '\0';
}

//Recupere la taille totale de la map pour la malloc
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
	free(str);
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
		return (ft_printf("Error.\nMap is empty or doesn't exist.\n"), NULL);
	map = malloc((i + 1) * sizeof(char *));
	*nb_line = i;
	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map[i] = get_next_line(fd);
	if (!map[i])
		return (free(map), NULL);
	while (map[i] != NULL)
	{
		replace_nl(map[i]);
		map[++i] = get_next_line(fd);
		if (!map[i] && i < *nb_line)
			return (free_the_map(map), NULL);
	}
	*nb_col = ft_strlen(map[0]);
	return (close(fd), map);
}
