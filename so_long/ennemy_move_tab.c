/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_move_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:50:18 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/27 16:01:10 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

//Déplace le G dans le tableau
void	move_ennemy_tab(t_global *global, char *dest, char *src)
{
	if (*dest == '0')
	{
		*dest = 'G';
		*src = '0';
		printf("OUI\n");
	}
	else if (*dest == 'P')
	{
		*dest = 'G';
		*src = '0';
		game_over(global);
	}
}

void	move_ennemy_up(t_global *global)
{
	int		x;
	int		y;

	y = 0;
	while (global->map[y])
	{
		x = 0;
		while (global->map[y][x])
		{
			if (global->map[y][x] == 'G')
				if (y && global->map[y - 1][x] != '1')
					return (move_ennemy_tab(global, &(global->map[y - 1][x]),
						&(global->map[y][x])));
			x++;
		}
		y++;
	}
}

void	move_ennemy_down(t_global *global)
{
	int		x;
	int		y;

	y = 0;
	while (global->map[y])
	{
		x = 0;
		while (global->map[y][x])
		{
			if (global->map[y][x] == 'G')
				if (global->map[y + 1] && global->map[y + 1][x] != '1')
					return (move_ennemy_tab(global, &(global->map[y + 1][x]),
						&(global->map[y][x])));
			x++;
		}
		y++;
	}
}

void	move_ennemy_right(t_global *global)
{
	int		x;
	int		y;

	y = 0;
	while (global->map[y])
	{
		x = 0;
		while (global->map[y][x])
		{
			if (global->map[y][x] == 'G')
				if (global->map[y][x + 1] && global->map[y][x + 1] != '1')
					return (move_ennemy_tab(global, &(global->map[y][x + 1]),
						&(global->map[y][x])));
			x++;
		}
		y++;
	}
}

void	move_ennemy_left(t_global *global)
{
	int		x;
	int		y;

	y = 0;
	while (global->map[y])
	{
		x = 0;
		while (global->map[y][x])
		{
			if (global->map[y][x] == 'G')
				if (x && global->map[y][x - 1] != '1')
					return (move_ennemy_tab(global, &(global->map[y][x - 1]),
						&(global->map[y][x])));
			x++;
		}
		y++;
	}
}
