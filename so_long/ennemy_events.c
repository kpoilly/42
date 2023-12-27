/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:11:38 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/27 20:45:26 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

void	game_over(t_global *global)
{
	printf("GAME OVER!");
	destroy(0, global);
}

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

void	ennemy_move(t_global *global)
{
	int	y;
	int	x;
	int	player_x;
	int	player_y;

	get_target(global, &player_x, &player_y);
	y = 0;
	while (global->map[y])
	{
		x = 0;
		while (global->map[y][x])
		{
			if (global->map[y][x] == 'G')
			{
				if ((player_x < x && player_x >= x - 3 && (player_y >= y - 3 && player_y <= y + 3)) && x && global->map[y][x - 1] != '1')
					return (move_ennemy_tab(global, &(global->map[y][x - 1]),
						&(global->map[y][x])));
				else if ((player_x > x && player_x <= x + 3 && (player_y >= y - 3 && player_y <= y + 3)) && global->map[y][x + 1]
					&& global->map[y][x + 1] != '1')
					return (move_ennemy_tab(global, &(global->map[y][x + 1]),
						&(global->map[y][x])));
				else if ((player_y < y && player_y >= y - 3) && y && global->map[y - 1][x] != '1')
					return (move_ennemy_tab(global, &(global->map[y - 1][x]),
						&(global->map[y][x])));
				else if ((player_y > y && player_y <= y + 3) && global->map[y + 1][x]
					&& global->map[y + 1][x] != '1')
					return (move_ennemy_tab(global, &(global->map[y + 1][x]),
						&(global->map[y][x])));
				else if (x && global->map[y][x - 1] != '1')
					return (move_ennemy_tab(global, &(global->map[y][x - 1]),
						&(global->map[y][x])));
				else if (global->map[y][x + 1] && global->map[y][x + 1] != '1')
					return (move_ennemy_tab(global, &(global->map[y][x + 1]),
						&(global->map[y][x])));
				else if (y && global->map[y - 1][x] != '1')
					return (move_ennemy_tab(global, &(global->map[y - 1][x]),
						&(global->map[y][x])));
				else if (global->map[y + 1][x] && global->map[y + 1][x] != '1')
					return (move_ennemy_tab(global, &(global->map[y + 1][x]),
						&(global->map[y][x])));
			}
			x++;
		}
		y++;
	}
}
