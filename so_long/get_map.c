/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:08:51 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/13 15:26:21 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

char	**get_map(char *filename, int *nb_line, int *nb_col)
{
	int		fd;
	int		i;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	//get_next_line jusqu'a null
	//on mets les return dans le tableau de char* 
	//(pb pour savoir combien d'element malloc pour le tableau)
	*nb_line = i;
	*nb_col = ft_strlen(map[0]);
	close(fd);
	return (map);
}

//get_next_line