/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:12:15 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/15 15:57:00 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

char	**check_error(char **map)
{
	if (!map)
		return (printf("Map is not readable.\n"), NULL);
	//check les erreurs suivantes :
	// - meme strlen sur chaque ligne
	// - ne contient rien d'autres que le charset "01CEP"
	// - contient au moins 1 : E, C et P
	// - ne contient pas plusieurs : E et P
	// - map entouree de 1
	// - check si tous les collectibles sont accessibles
	return (map);
}
