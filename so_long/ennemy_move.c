/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:50:18 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/02 14:55:09 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

//Joueur vu, l'ennemi le traque
void	track_player(t_global *global, int x, int y)
{
	if (global->player.x < x && x && (global->map[y][x - 1] == '0'
		|| global->map[y][x - 1] == 'P'))
		return (move_ennemy_tab(global, &(global->map[y][x - 1]),
			&(global->map[y][x])));
	else if (global->player.x > x && global->map[y][x + 1]
		&& (global->map[y][x + 1] == '0' || global->map[y][x + 1] == 'P'))
		return (move_ennemy_tab(global, &(global->map[y][x + 1]),
			&(global->map[y][x])));
	else if (global->player.y < y && y && (global->map[y - 1][x] == '0'
		|| global->map[y - 1][x] == 'P'))
		return (move_ennemy_tab(global, &(global->map[y - 1][x]),
			&(global->map[y][x])));
	else if (global->player.y > y && global->map[y + 1]
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
	else if (global->map[y + 1] && (global->map[y + 1][x] == '0'
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
	else if (global->map[y + 1] && (global->map[y + 1][x] == '0'
		|| global->map[y + 1][x] == 'P'))
		return (move_ennemy_tab(global, &(global->map[y + 1][x]),
			&(global->map[y][x])));
	else if (global->map[y][x + 1] && (global->map[y][x + 1] != '0'
		|| global->map[y][x + 1] != 'P'))
		return (move_ennemy_tab(global, &(global->map[y][x + 1]),
			&(global->map[y][x])));
}

//L'ennemi cherche a aller vers la gauche
void	search_down(t_global *global, int x, int y)
{	
	if (global->map[y + 1] && (global->map[y + 1][x] == '0'
		|| global->map[y + 1][x] == 'P'))
		return (move_ennemy_tab(global, &(global->map[y + 1][x]),
			&(global->map[y][x])));
	else if (x && (global->map[y][x - 1] == '0'
		|| global->map[y][x - 1] == 'P'))
		return (move_ennemy_tab(global, &(global->map[y][x - 1]),
			&(global->map[y][x])));
	else if (global->map[y][x + 1] && (global->map[y][x + 1] != '0'
		|| global->map[y][x + 1] != 'P'))
		return (move_ennemy_tab(global, &(global->map[y][x + 1]),
			&(global->map[y][x])));
	else if (y && (global->map[y - 1][x] == '0'
		|| global->map[y - 1][x] == 'P'))
		return (move_ennemy_tab(global, &(global->map[y - 1][x]),
			&(global->map[y][x])));
}

//L'ennemi cherche a aller vers la gauche
void	search_up(t_global *global, int x, int y)
{	
	if (global->map[y - 1] && (global->map[y - 1][x] == '0'
		|| global->map[y - 1][x] == 'P'))
		return (move_ennemy_tab(global, &(global->map[y - 1][x]),
			&(global->map[y][x])));
	else if (x && (global->map[y][x - 1] == '0'
		|| global->map[y][x - 1] == 'P'))
		return (move_ennemy_tab(global, &(global->map[y][x - 1]),
			&(global->map[y][x])));
	else if (global->map[y][x + 1] && (global->map[y][x + 1] != '0'
		|| global->map[y][x + 1] != 'P'))
		return (move_ennemy_tab(global, &(global->map[y][x + 1]),
			&(global->map[y][x])));
	else if (y && (global->map[y + 1][x] == '0'
		|| global->map[y + 1][x] == 'P'))
		return (move_ennemy_tab(global, &(global->map[y + 1][x]),
			&(global->map[y][x])));
}
