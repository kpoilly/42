/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:10:55 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/11 18:43:32 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

//verifie si tous les collectibles et la sortie sont accessibles
int	check_path(t_global *global)
{
	char	**dup;

	dup = map_dup(global->map);
	if (!dup)
		return (0);
	set_coord(global, &(global->player));
	flood_fill(dup, global->player.x, global->player.y);
	if (!is_reachable(dup))
		return (free_the_map(dup), 0);
	free_the_map(dup);
	return (1);
}

//duplique la map pour ne pas l'alterer
char	**map_dup(char **map)
{
	char	**dup;
	int		i;

	i = 0;
	while (map[i])
		i++;
	dup = malloc((i + 1) * sizeof(char *));
	i = 0;
	while (map[i])
	{
		dup[i] = ft_strdup(map[i]);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

//check si il reste des C et E non touches pas le floodfill
int	is_reachable(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				return (ft_printf("Error.\nSome frogs are trapped :(\n"), 0);
			if (map[y][x] == 'E')
				return (ft_printf("Error.\nExit is unreachable.\n"), 0);
			x++;
		}
		y++;
	}
	return (1);
}

//repends des # dans tous les espaces accessibles de la map
char	**flood_fill(char **map, int x, int y)
{
	if (y >= 0 && x >= 0 && map[y] && map[y][x]
		&& (map[y][x] == '0' || map[y][x] == 'C'
		|| map[y][x] == 'P' || map[y][x] == 'E'))
	{
		map[y][x] = '#';
		flood_fill(map, x, (y - 1));
		flood_fill(map, x, (y + 1));
		flood_fill(map, (x + 1), y);
		flood_fill(map, (x - 1), y);
	}
	return (map);
}
