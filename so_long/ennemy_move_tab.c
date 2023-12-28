/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_move_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:50:18 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/28 16:05:46 by kpoilly          ###   ########.fr       */
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
	}
	else if (*dest == 'P')
	{
		*dest = 'G';
		*src = '0';
		game_over(global);
	}
}

void	track_player(t_global *global, int x, int y)
{
	if (global->player.x < x && x && (global->map[y][x - 1] == '0'
		|| global->map[y][x - 1] == 'P'))
		return (move_ennemy_tab(global, &(global->map[y][x - 1]),
			&(global->map[y][x])));
	else if (global->player.x > x && global->map[y][x + 1]
		&& (global->map[y][x + 1] != '0' || global->map[y][x + 1] != 'P'))
		return (move_ennemy_tab(global, &(global->map[y][x + 1]),
			&(global->map[y][x])));
	else if (global->player.y < y && y && (global->map[y - 1][x] == '0'
		|| global->map[y - 1][x] == 'P'))
		return (move_ennemy_tab(global, &(global->map[y - 1][x]),
			&(global->map[y][x])));
	else if (global->player.y > y && global->map[y + 1][x]
		&& (global->map[y + 1][x] == '0' || global->map[y + 1][x] == 'P'))
		return (move_ennemy_tab(global, &(global->map[y + 1][x]),
			&(global->map[y][x])));
}

//L'ennemi cherche a aller vers la droite
void	search_right(t_global *global, int x, int y)
{
	if (global->map[y][x + 1] && (global->map[y][x + 1] == '0'
		|| global->map[y][x + 1] == 'P'))
		return (move_ennemy_tab(global, &(global->map[y][x + 1]),
			&(global->map[y][x])));
	else if (y && (global->map[y - 1][x] == '0'
		|| global->map[y - 1][x] == 'P'))
		return (move_ennemy_tab(global, &(global->map[y - 1][x]),
			&(global->map[y][x])));
	else if (global->map[y + 1][x] && (global->map[y + 1][x] == '0'
		|| global->map[y + 1][x] == 'P'))
		return (move_ennemy_tab(global, &(global->map[y + 1][x]),
			&(global->map[y][x])));
	else if (x && (global->map[y][x - 1] == '0'
		|| global->map[y][x - 1] == 'P'))
		return (move_ennemy_tab(global, &(global->map[y][x - 1]),
			&(global->map[y][x])));
}

//L'ennemi cherche a aller vers la gauche
void	search_left(t_global *global, int x, int y)
{	
	if (x && (global->map[y][x - 1] == '0' || global->map[y][x - 1] == 'P'))
		return (move_ennemy_tab(global, &(global->map[y][x - 1]),
			&(global->map[y][x])));
	else if (y && (global->map[y - 1][x] == '0'
		|| global->map[y - 1][x] == 'P'))
		return (move_ennemy_tab(global, &(global->map[y - 1][x]),
			&(global->map[y][x])));
	else if (global->map[y + 1][x] && (global->map[y + 1][x] == '0'
		|| global->map[y + 1][x] == 'P'))
		return (move_ennemy_tab(global, &(global->map[y + 1][x]),
			&(global->map[y][x])));
	else if (global->map[y][x + 1] && (global->map[y][x + 1] != '0'
		|| global->map[y][x + 1] != 'P'))
		return (move_ennemy_tab(global, &(global->map[y][x + 1]),
			&(global->map[y][x])));
}

void	ennemy_move(t_global *global)
{
	int	y;
	int	x;

	get_target(global, &global->player.x, &global->player.y);
	y = 0;
	while (global->map[y])
	{
		x = 0;
		while (global->map[y][x])
		{
			if (global->map[y][x] == 'G')
			{
				if (!in_range(global->player.x, global->player.y, x, y))
					return (find_path(global, x, y));
				else
					return (track_player(global, x, y));
			}
			x++;
		}
		y++;
	}
}
