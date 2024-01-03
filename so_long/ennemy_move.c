/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:57:39 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/03 17:10:56 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

//bouge le gobelin toutes les x milliseconds
void	move_ennemy(t_global *global)
{
	int		time;
	int		rage;

	time = ((long double)(clock() - global->last) / CLOCKS_PER_SEC) * 1000;
	get_target(global, &global->player);
	get_target(global, &global->ennemy);
	if (in_range(global->player.x, global->player.y,
			global->ennemy.x, global->ennemy.y) || !global->nbcollec)
		rage = 100;
	else
		rage = 250;
	if (time >= rage)
	{
		global->last = clock();
		ennemy_decision(global);
		render_map(global, global->last_state);
	}
}

//choisi la direction du gobelin en fonction de si le joueur est dans sa range
void	ennemy_decision(t_global *global)
{
	if (!in_range(global->player.x, global->player.y,
			global->ennemy.x, global->ennemy.y))
		return (patrol(global, global->ennemy.x, global->ennemy.y));
	else
		return (track_player(global, global->ennemy.x, global->ennemy.y));
}

//Joueur vu, l'ennemi le traque
void	track_player(t_global *global, int x, int y)
{
	if (global->player.y < y && y)
		return (search_up(global, x, y));
	else if (global->player.y > y && global->map[y + 1])
		return (search_down(global, x, y));
	else if (global->player.x < x && x)
		return (search_left(global, x, y));
	else if (global->player.x > x && global->map[y][x + 1])
		return (search_right(global, x, y));
	return (patrol(global, x, y));
}

//set la derniere direction de l'ennemi, pour eviter de revenir en arriere
void	set_lastdir(t_global *global, char dir)
{
		global->last_gobdir = dir;
}

//Patrouille de maniere aleatoire
void	patrol(t_global *global, int x, int y)
{
	int	dir;

	dir = rand() % 4;
	if (dir == 0 && global->last_gobdir != 'R')
		search_left(global, x, y);
	else if (dir == 1 && global->last_gobdir != 'L')
		search_right(global, x, y);
	else if (dir == 2 && global->last_gobdir != 'D')
		search_up(global, x, y);
	else if (dir == 3 && global->last_gobdir != 'U')
		search_down(global, x, y);
	else
	{
		set_lastdir(global, 'W');
		patrol(global, x, y);
	}
}
