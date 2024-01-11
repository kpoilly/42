/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_directions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:50:18 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/11 18:46:23 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data/headers/so_long.h"

//set la derniere orientation de l'entite, et sa derniere direction
void	set_state(t_ent *entity, char direction)
{
	if (direction == 'U')
		entity->last_state = entity->back;
	if (direction == 'D' || direction == 'W')
		entity->last_state = entity->front;
	if (direction == 'L')
		entity->last_state = entity->left;
	if (direction == 'R')
		entity->last_state = entity->right;
	entity->last_dir = direction;
}

//L'ennemi cherche a aller vers la droite
void	search_right(t_global *global, int x, int y)
{
	if (global->map[y][x + 1] && (global->map[y][x + 1] == '0'
		|| global->map[y][x + 1] == 'P') && global->enemy.last_dir != 'L')
		return (set_state (&global->enemy, 'R'),
			move_enemy_tab(global, &(global->map[y][x + 1]),
			&(global->map[y][x])));
	else if (y && (global->map[y - 1][x] == '0'
		|| global->map[y - 1][x] == 'P') && global->enemy.last_dir != 'D')
		return (set_state (&global->enemy, 'U'),
			move_enemy_tab(global, &(global->map[y - 1][x]),
			&(global->map[y][x])));
	else if (global->map[y + 1] && (global->map[y + 1][x] == '0'
		|| global->map[y + 1][x] == 'P') && global->enemy.last_dir != 'U')
		return (set_state (&global->enemy, 'D'),
			move_enemy_tab(global, &(global->map[y + 1][x]),
			&(global->map[y][x])));
	else if (x && (global->map[y][x - 1] == '0'
		|| global->map[y][x - 1] == 'P') && global->enemy.last_dir != 'R')
		return (set_state (&global->enemy, 'L'),
			move_enemy_tab(global, &(global->map[y][x - 1]),
			&(global->map[y][x])));
	return (patrol(global, x, y));
}

//L'ennemi cherche a aller vers la gauche
void	search_left(t_global *global, int x, int y)
{	
	if (x && (global->map[y][x - 1] == '0' || global->map[y][x - 1] == 'P')
		&& global->enemy.last_dir != 'R')
		return (set_state (&global->enemy, 'L'),
			move_enemy_tab(global, &(global->map[y][x - 1]),
			&(global->map[y][x])));
	else if (y && (global->map[y - 1][x] == '0'
		|| global->map[y - 1][x] == 'P') && global->enemy.last_dir != 'D')
		return (set_state (&global->enemy, 'U'),
			move_enemy_tab(global, &(global->map[y - 1][x]),
			&(global->map[y][x])));
	else if (global->map[y + 1] && (global->map[y + 1][x] == '0'
		|| global->map[y + 1][x] == 'P') && global->enemy.last_dir != 'U')
		return (set_state (&global->enemy, 'D'),
			move_enemy_tab(global, &(global->map[y + 1][x]),
			&(global->map[y][x])));
	else if (global->map[y][x + 1] && (global->map[y][x + 1] == '0'
		|| global->map[y][x + 1] == 'P') && global->enemy.last_dir != 'L')
		return (set_state (&global->enemy, 'R'),
			move_enemy_tab(global, &(global->map[y][x + 1]),
			&(global->map[y][x])));
	return (patrol(global, x, y));
}

//L'ennemi cherche a aller vers la gauche
void	search_down(t_global *global, int x, int y)
{	
	if (global->map[y + 1] && (global->map[y + 1][x] == '0'
		|| global->map[y + 1][x] == 'P') && global->enemy.last_dir != 'U')
		return (set_state (&global->enemy, 'D'),
			move_enemy_tab(global, &(global->map[y + 1][x]),
			&(global->map[y][x])));
	else if (x && (global->map[y][x - 1] == '0'
		|| global->map[y][x - 1] == 'P') && global->enemy.last_dir != 'R'
		&& x > global->player.x)
		return (set_state (&global->enemy, 'L'),
			move_enemy_tab(global, &(global->map[y][x - 1]),
			&(global->map[y][x])));
	else if (global->map[y][x + 1] && (global->map[y][x + 1] == '0'
		|| global->map[y][x + 1] == 'P') && global->enemy.last_dir != 'L')
		return (set_state (&global->enemy, 'R'),
			move_enemy_tab(global, &(global->map[y][x + 1]),
			&(global->map[y][x])));
	else if (y && (global->map[y - 1][x] == '0'
		|| global->map[y - 1][x] == 'P') && global->enemy.last_dir != 'D')
		return (set_state (&global->enemy, 'U'),
			move_enemy_tab(global, &(global->map[y - 1][x]),
			&(global->map[y][x])));
}

//L'ennemi cherche a aller vers la gauche
void	search_up(t_global *global, int x, int y)
{	
	if (global->map[y - 1] && (global->map[y - 1][x] == '0'
		|| global->map[y - 1][x] == 'P') && global->enemy.last_dir != 'D')
		return (set_state (&global->enemy, 'U'),
			move_enemy_tab(global, &(global->map[y - 1][x]),
			&(global->map[y][x])));
	else if (x && (global->map[y][x - 1] == '0'
		|| global->map[y][x - 1] == 'P') && global->enemy.last_dir != 'R'
		&& x > global->player.x)
		return (set_state (&global->enemy, 'L'),
			move_enemy_tab(global, &(global->map[y][x - 1]),
			&(global->map[y][x])));
	else if (global->map[y][x + 1] && (global->map[y][x + 1] == '0'
		|| global->map[y][x + 1] == 'P') && global->enemy.last_dir != 'L')
		return (set_state (&global->enemy, 'R'),
			move_enemy_tab(global, &(global->map[y][x + 1]),
			&(global->map[y][x])));
	else if (y && (global->map[y + 1][x] == '0'
		|| global->map[y + 1][x] == 'P') && global->enemy.last_dir != 'U')
		return (set_state (&global->enemy, 'D'),
			move_enemy_tab(global, &(global->map[y + 1][x]),
			&(global->map[y][x])));
	return (patrol(global, x, y));
}
