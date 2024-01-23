/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:57:39 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/22 16:49:13 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data/headers/so_long.h"

//bouge le gobelin toutes les x milliseconds
void	move_enemy(t_global *global)
{
	int		time;
	int		speed;

	time = ((long double)(clock() - global->last) / CLOCKS_PER_SEC) * 1000;
	set_coord(global, &global->player);
	set_coord(global, &global->enemy);
	if (in_range(global->player.x, global->player.y,
			global->enemy.x, global->enemy.y) || !global->nbcollec)
		speed = 100;
	else
		speed = 250;
	if (time >= speed)
	{
		global->last = clock();
		enemy_decision(global);
		if (speed == 100 && global->enemy.last_state.next)
			global->enemy.last_state = *global->enemy.last_state.next;
		if (speed != 100 && global->enemy.last_state.prev)
			global->enemy.last_state = *global->enemy.last_state.prev;
		render_map(global, global->player.last_state);
	}
}

//choisi la direction du gobelin en fonction de si le joueur est dans sa range
void	enemy_decision(t_global *global)
{
	if (!in_range(global->player.x, global->player.y,
			global->enemy.x, global->enemy.y))
		return (patrol(global, global->enemy.x, global->enemy.y));
	else
		return (track_player(global, global->enemy.x, global->enemy.y));
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

//Patrouille de maniere aleatoire
void	patrol(t_global *global, int x, int y)
{
	int	dir;

	dir = rand() % 4;
	if (dir == 0 && global->enemy.last_dir != 'R')
		search_left(global, x, y);
	else if (dir == 1 && global->enemy.last_dir != 'L')
		search_right(global, x, y);
	else if (dir == 2 && global->enemy.last_dir != 'D')
		search_up(global, x, y);
	else if (dir == 3 && global->enemy.last_dir != 'U')
		search_down(global, x, y);
	else
	{
		set_state(&global->enemy, 'W');
		patrol(global, x, y);
	}
}
