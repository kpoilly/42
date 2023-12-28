/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_patrol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:57:39 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/28 20:04:01 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

static void	check_left(t_global *global, int x, int y)
{
	if (x && (global->map[y][x - 1] == '0' || global->map[y][x - 1] == 'P'))
		return (move_ennemy_tab(global, &(global->map[y][x - 1]),
			&(global->map[y][x])));
	else
		patrol(global, x, y);
}

static void	check_right(t_global *global, int x, int y)
{
	if (global->map[y][x + 1] && (global->map[y][x + 1] == '0'
		|| global->map[y][x + 1] == 'P'))
		return (move_ennemy_tab(global, &(global->map[y][x + 1]),
			&(global->map[y][x])));
	else
		patrol(global, x, y);
}

static void	check_up(t_global *global, int x, int y)
{
	if (y && (global->map[y - 1][x] == '0' || global->map[y - 1][x] == 'P'))
		return (move_ennemy_tab(global, &(global->map[y - 1][x]),
			&(global->map[y][x])));
	else
		patrol(global, x, y);
}

static void	check_down(t_global *global, int x, int y)
{
	if (global->player.y > y && global->map[y + 1]
		&& (global->map[y + 1][x] == '0' || global->map[y + 1][x] == 'P'))
		return (move_ennemy_tab(global, &(global->map[y + 1][x]),
			&(global->map[y][x])));
	else
		patrol(global, x, y);
}

void	patrol(t_global *global, int x, int y)
{
	int	dir;

	dir = rand() % 4;
	if (dir == 0)
		check_left(global, x, y);
	else if (dir == 1)
		check_right(global, x, y);
	else if (dir == 2)
		check_up(global, x, y);
	else if (dir == 3)
		check_down(global, x, y);
}
