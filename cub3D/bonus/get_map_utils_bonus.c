/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:49:49 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/11 11:08:54 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/cub3D.h"

int	map_charset(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == 'D')
		return (1);
	return (0);
}

int	map_begin(char	*line)
{
	if (line[0] == '\n')
		return (0);
	while (*line && *line != '\n')
	{
		if (*line != ' ' && (*line < '0' || *line > '9'))
			return (0);
		line++;
	}
	return (1);
}

int	ft_only_nb(char	**tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] < '0' || tab[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_tablen(char	**tab)
{
	int	len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

int	*get_bg_colors(char *line)
{
	int		i;
	int		*res;
	char	*clear;
	char	**check;

	i = 0;
	while (!(line[i] >= '0' && line[i] <= '9'))
		i++;
	clear = ft_strdup(line + i);
	if (!clear)
		return (NULL);
	check = ft_split(clear, ", \n");
	if (!check)
		return (NULL);
	free(clear);
	if (!ft_only_nb(check) || ft_tablen(check) != 3)
		return (free_tab(check), NULL);
	res = malloc(3 * sizeof(int));
	if (!res)
		return (NULL);
	i = -1;
	while (check[++i])
		res[i] = ft_atoi(check[i]);
	return (free_tab(check), res);
}
