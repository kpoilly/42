/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:33:20 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/25 13:28:41 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data/headers/so_long.h"

//set les next et prev des images enemy pour anim
void	enemy_setup(t_global *global)
{
	global->enemy.front.next = &global->enemy.front2;
	global->enemy.front2.next = NULL;
	global->enemy.front2.prev = &global->enemy.front;
	global->enemy.front.prev = NULL;
	global->enemy.back.next = &global->enemy.back2;
	global->enemy.back2.next = NULL;
	global->enemy.back2.prev = &global->enemy.back;
	global->enemy.back.prev = NULL;
	global->enemy.right.next = &global->enemy.right2;
	global->enemy.right2.next = NULL;
	global->enemy.right2.prev = &global->enemy.right;
	global->enemy.right.prev = NULL;
	global->enemy.left.next = &global->enemy.left2;
	global->enemy.left2.next = NULL;
	global->enemy.left2.prev = &global->enemy.left;
	global->enemy.left.prev = NULL;
	global->enemy.last_dir = 'W';
	global->enemy.last_state = global->enemy.front;
}

//Fait apparaitre l'ennemi aleatoirement sur la map
void	spawn_enemy(t_global *global, int nb_line, int nb_col)
{
	int		x;
	int		y;
	int		tries;

	srand(time(NULL));
	x = 0;
	y = 0;
	tries = 0;
	while ((global->map[y][x] != '0'
		|| in_range(x, y, global->player.x, global->player.y))
		&& tries < 500)
	{
		y = rand() % nb_line;
		x = rand() % nb_col;
		tries++;
	}
	if (tries == 500)
		return (write(2, "Error.\nNot enough space for enemy.\n", 35),
			(void)destroy(global));
	enemy_setup(global);
	global->map[y][x] = global->enemy.chara;
}
