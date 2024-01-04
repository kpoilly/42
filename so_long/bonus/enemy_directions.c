/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_directions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:50:18 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/04 11:51:22 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data/headers/so_long.h"

//L'ennemi cherche a aller vers la droite
void	search_right(t_global *global, int x, int y)
{
	if (global->map[y][x + 1] && (global->map[y][x + 1] == '0'
		|| global->map[y][x + 1] == 'P') && global->last_gobdir != 'L')
		return (set_lastdir(global, 'R'),
			move_enemy_tab(global, &(global->map[y][x + 1]),
			&(global->map[y][x])));
	else if (y && (global->map[y - 1][x] == '0'
		|| global->map[y - 1][x] == 'P') && global->last_gobdir != 'D')
		return (set_lastdir(global, 'U'),
			move_enemy_tab(global, &(global->map[y - 1][x]),
			&(global->map[y][x])));
	else if (global->map[y + 1] && (global->map[y + 1][x] == '0'
		|| global->map[y + 1][x] == 'P') && global->last_gobdir != 'U')
		return (set_lastdir(global, 'D'),
			move_enemy_tab(global, &(global->map[y + 1][x]),
			&(global->map[y][x])));
	else if (x && (global->map[y][x - 1] == '0'
		|| global->map[y][x - 1] == 'P') && global->last_gobdir != 'R')
		return (set_lastdir(global, 'L'),
			move_enemy_tab(global, &(global->map[y][x - 1]),
			&(global->map[y][x])));
	return (patrol(global, x, y));
}

//L'ennemi cherche a aller vers la gauche
void	search_left(t_global *global, int x, int y)
{	
	if (x && (global->map[y][x - 1] == '0' || global->map[y][x - 1] == 'P')
		&& global->last_gobdir != 'R')
		return (set_lastdir(global, 'L'),
			move_enemy_tab(global, &(global->map[y][x - 1]),
			&(global->map[y][x])));
	else if (y && (global->map[y - 1][x] == '0'
		|| global->map[y - 1][x] == 'P') && global->last_gobdir != 'D')
		return (set_lastdir(global, 'U'),
			move_enemy_tab(global, &(global->map[y - 1][x]),
			&(global->map[y][x])));
	else if (global->map[y + 1] && (global->map[y + 1][x] == '0'
		|| global->map[y + 1][x] == 'P') && global->last_gobdir != 'U')
		return (set_lastdir(global, 'D'),
			move_enemy_tab(global, &(global->map[y + 1][x]),
			&(global->map[y][x])));
	else if (global->map[y][x + 1] && (global->map[y][x + 1] == '0'
		|| global->map[y][x + 1] == 'P') && global->last_gobdir != 'L')
		return (set_lastdir(global, 'R'),
			move_enemy_tab(global, &(global->map[y][x + 1]),
			&(global->map[y][x])));
	return (patrol(global, x, y));
}

//L'ennemi cherche a aller vers la gauche
void	search_down(t_global *global, int x, int y)
{	
	if (global->map[y + 1] && (global->map[y + 1][x] == '0'
		|| global->map[y + 1][x] == 'P') && global->last_gobdir != 'U')
		return (set_lastdir(global, 'D'),
			move_enemy_tab(global, &(global->map[y + 1][x]),
			&(global->map[y][x])));
	else if (x && (global->map[y][x - 1] == '0'
		|| global->map[y][x - 1] == 'P') && global->last_gobdir != 'R'
		&& x > global->player.x)
		return (set_lastdir(global, 'L'),
			move_enemy_tab(global, &(global->map[y][x - 1]),
			&(global->map[y][x])));
	else if (global->map[y][x + 1] && (global->map[y][x + 1] == '0'
		|| global->map[y][x + 1] == 'P') && global->last_gobdir != 'L')
		return (set_lastdir(global, 'R'),
			move_enemy_tab(global, &(global->map[y][x + 1]),
			&(global->map[y][x])));
	else if (y && (global->map[y - 1][x] == '0'
		|| global->map[y - 1][x] == 'P') && global->last_gobdir != 'D')
		return (set_lastdir(global, 'U'),
			move_enemy_tab(global, &(global->map[y - 1][x]),
			&(global->map[y][x])));
}

//L'ennemi cherche a aller vers la gauche
void	search_up(t_global *global, int x, int y)
{	
	if (global->map[y - 1] && (global->map[y - 1][x] == '0'
		|| global->map[y - 1][x] == 'P') && global->last_gobdir != 'D')
		return (set_lastdir(global, 'U'),
			move_enemy_tab(global, &(global->map[y - 1][x]),
			&(global->map[y][x])));
	else if (x && (global->map[y][x - 1] == '0'
		|| global->map[y][x - 1] == 'P') && global->last_gobdir != 'R'
		&& x > global->player.x)
		return (set_lastdir(global, 'L'),
			move_enemy_tab(global, &(global->map[y][x - 1]),
			&(global->map[y][x])));
	else if (global->map[y][x + 1] && (global->map[y][x + 1] == '0'
		|| global->map[y][x + 1] == 'P') && global->last_gobdir != 'L')
		return (set_lastdir(global, 'R'),
			move_enemy_tab(global, &(global->map[y][x + 1]),
			&(global->map[y][x])));
	else if (y && (global->map[y + 1][x] == '0'
		|| global->map[y + 1][x] == 'P') && global->last_gobdir != 'U')
		return (set_lastdir(global, 'D'),
			move_enemy_tab(global, &(global->map[y + 1][x]),
			&(global->map[y][x])));
	return (patrol(global, x, y));
}
