/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:12:15 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/19 08:48:35 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

//Compte le nombre de collectibles dans la map
int	count_collec(char	**map, t_global *global, int *nb_exit, int *nb_player)
{
	*nb_exit = 0;
	*nb_player = 0;
	global->nbcollec = 0;
	(void)map;
	//return 0 si !in_charset("01CEP")
	return (1);
}

//Check les différentes erreurs de map
char	**check_error(char **map, t_global *global)
{	
	//int	nb_exit;
	//int	nb_player;
	(void)global;
	if (!map)
		return (ft_printf("Error.\nMap is not readable.\n"), NULL);
	// count_collec(map, global, &nb_exit, &nb_player);
	// if (!global->nbcollec)
	// 	return (ft_printf("Error.\nToo few collectibles.\n"), NULL);
	// if (!nb_exit)
	// 	return (ft_printf("Error.\nNo exit on the map.\n"), NULL);
	// if (!nb_player)
	// 	return (ft_printf("Error.\nNo Player on the map.\n"), NULL);
	// if (nb_exit > 1)
	// 	return (ft_printf("Error.\nToo many exit on the map.\n"), NULL);
	// if (nb_player > 1)
	// 	return (ft_printf("Error.\nThe game is not multiplayer !\n"), NULL);
	//check les erreurs suivantes :
	// - meme strlen sur chaque ligne
	// - ne contient rien d'autres que le charset "01CEP"
	// - contient au moins 1 : E, C et P
	// - ne contient pas plusieurs : E et P
	// - map entouree de 1
	// - check si tous les collectibles sont accessibles
	return (map);
}
