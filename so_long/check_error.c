/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:12:15 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/17 16:37:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

//Check les différentes erreurs de map
char	**check_error(char **map, t_global *global)
{
	int	nbcollec;

	if (!map)
		return (ft_printf("Error.\nMap is not readable.\n"), NULL);
	nbcollec = 0;
	//check les erreurs suivantes :
	// - meme strlen sur chaque ligne
	// - ne contient rien d'autres que le charset "01CEP"
	// - contient au moins 1 : E, C et P
	// - ne contient pas plusieurs : E et P
	// - map entouree de 1
	// - check si tous les collectibles sont accessibles
	global->nbcollec = nbcollec;
	return (map);
}
