/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:12:15 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/02 08:13:33 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

//Verifie si la map est entouree de 1
static int	surrounded(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((!x || !y || !map[y + 1] || !map[y][x + 1]) && map[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

//verifie si un char fait partie d'un charset
static int	in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

// Compte le nombre de collectibles dans la map
int	count_collec(char **map, t_global *global, int *nb_exit, int *nb_player)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!in_charset(map[y][x], "01CEP"))
				return (ft_printf("Error.\n"),
					ft_printf("An unrecognized character is Among Us.\n"), 0);
			if (map[y][x] == 'C')
				global->nbcollec++;
			if (map[y][x] == 'E')
				(*nb_exit)++;
			if (map[y][x] == 'P')
				(*nb_player)++;
			x++;
		}
		if (x != ft_strlen(map[0]))
			return (ft_printf("Error.\nDifferent line size."), 0);
		y++;
	}
	return (1);
}

// Check les différentes erreurs de map
char	**check_error(char **map, t_global *global)
{
	int	nb_exit;
	int	nb_player;

	nb_exit = 0;
	nb_player = 0;
	global->nbcollec = 0;
	if (!map)
		return (ft_printf("Error.\nMap is not readable.\n"), NULL);
	if (!surrounded(map))
		return (ft_printf("Error.\nMap is not surrounded by walls.\n"), NULL);
	if (!count_collec(map, global, &nb_exit, &nb_player))
		return (NULL);
	if (!global->nbcollec)
		return (ft_printf("Error.\nToo few collectibles.\n"), NULL);
	if (!nb_exit)
		return (ft_printf("Error.\nNo exit on the map.\n"), NULL);
	if (!nb_player)
		return (ft_printf("Error.\nNo Player on the map.\n"), NULL);
	if (nb_exit > 1)
		return (ft_printf("Error.\nToo many exit on the map.\n"), NULL);
	if (nb_player > 1)
		return (ft_printf("Error.\nThe game is not multiplayer !\n"), NULL);
	// if (!flood fill(map))
	// 	return (ft_printf("Error.\nCollectibles not accessible.\n"), NULL);
	return (map);
}
