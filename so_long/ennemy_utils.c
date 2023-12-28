/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:11:38 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/28 16:11:26 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

//Recupere la coordonne du joueur dans la map
void	get_target(t_global *global, int *x, int *y)
{
	*x = 0;
	*y = 0;

	while (global->map[*y])
	{
		*x = 0;
		while (global->map[*y][*x])
		{
			if (global->map[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

//Verifie si le joueur se trouve dans la range de vision de l'ennemi
int	in_range(int player_x, int player_y, int x, int y)
{
	return ((player_x >= x - 3 && player_x <= x + 3)
		&& (player_y >= y - 3 && player_y <= y + 3));
}

//L'ennemi cherche un chemin de parcours pour se rapprocher du milieu
void	find_path(t_global *global, int x, int y)
{
	if (global->player.x >= ((global->mlx.width / 50) / 2))
		return (ft_printf(">>"), search_right(global, x, y));
	else
		return (ft_printf("<<"), search_left(global, x, y));
}

// void	ennemy_move(t_global *global)
// {
// 	int	y;
// 	int	x;

// 	get_target(global, &global->player.x, &global->player.y);
// 	y = 0;
// 	while (global->map[y])
// 	{
// 		x = 0;
// 		while (global->map[y][x])
// 		{
// 			if (global->map[y][x] == 'G')
// 			{
// 				if ((player_x < x && player_x >= x - 3 && (player_y >= y - 3 && player_y <= y + 3)) && x && global->map[y][x - 1] != '1')
// 					return (move_ennemy_tab(global, &(global->map[y][x - 1]),
// 						&(global->map[y][x])));
// 				else if ((player_x > x && player_x <= x + 3 && (player_y >= y - 3 && player_y <= y + 3)) && global->map[y][x + 1]
// 					&& global->map[y][x + 1] != '1')
// 					return (move_ennemy_tab(global, &(global->map[y][x + 1]),
// 						&(global->map[y][x])));
// 				else if ((player_y < y && player_y >= y - 3 && (player_x >= x - 3 && player_x <= x + 3)) && y && global->map[y - 1][x] != '1')
// 					return (move_ennemy_tab(global, &(global->map[y - 1][x]),
// 						&(global->map[y][x])));
// 				else if ((player_y > y && player_y <= y + 3 && (player_x >= x - 3 && player_x <= x + 3)) && global->map[y + 1][x]
// 					&& global->map[y + 1][x] != '1')
// 					return (move_ennemy_tab(global, &(global->map[y + 1][x]),
// 						&(global->map[y][x])));
// 				else if (x && global->map[y][x - 1] != '1')
// 					return (move_ennemy_tab(global, &(global->map[y][x - 1]),
// 						&(global->map[y][x])));
// 				else if (global->map[y][x + 1] && global->map[y][x + 1] != '1')
// 					return (move_ennemy_tab(global, &(global->map[y][x + 1]),
// 						&(global->map[y][x])));
// 				else if (y && global->map[y - 1][x] != '1')
// 					return (move_ennemy_tab(global, &(global->map[y - 1][x]),
// 						&(global->map[y][x])));
// 				else if (global->map[y + 1][x] && global->map[y + 1][x] != '1')
// 					return (move_ennemy_tab(global, &(global->map[y + 1][x]),
// 						&(global->map[y][x])));
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }
