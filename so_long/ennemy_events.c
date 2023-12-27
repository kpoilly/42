/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:11:38 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/27 16:00:17 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

void	game_over(t_global *global)
{
	printf("GAME OVER!");
	destroy(0, global);
}

void	ennemy_move(t_global *global)
{
	int	y;
	int	x;
	int	player;

	player = 0;
	y = 0;
	while (global->map[y])
	{
		x = 0;
		while (global->map[y][x])
		{
			if (global->map[y][x] == 'P')
				player++;
			if (global->map[y][x] == 'G')
			{
				if (player && x && global->map[y][x - 1] != '1')
					return (ft_printf("<"), move_ennemy_tab(global, &(global->map[y][x - 1]),
						&(global->map[y][x - 1])));
				else if (player && y && global->map[y - 1][x] != '1')
					return (ft_printf("^"), move_ennemy_tab(global, &(global->map[y - 1][x]),
						&(global->map[y - 1][x])));
				else if (global->map[y + 1][x] && global->map[y + 1][x] != '1')
					return (ft_printf("v"), move_ennemy_tab(global, &(global->map[y + 1][x]),
						&(global->map[y + 1][x])));
				else if (global->map[y][x + 1] && global->map[y][x + 1] != '1')
					return (ft_printf(">"), move_ennemy_tab(global, &(global->map[y][x + 1]),
						&(global->map[y][x + 1])));
				else if (y && global->map[y - 1][x] && global->map[y - 1][x] != '1')
					return (ft_printf("^"), move_ennemy_tab(global, &(global->map[y - 1][x]),
						&(global->map[y - 1][x])));
				else if (x && global->map[y][x - 1] != '1')
					return (ft_printf("<"), move_ennemy_tab(global, &(global->map[y][x - 1]),
						&(global->map[y][x - 1])));
			}
			x++;
		}
		y++;
	}
}
