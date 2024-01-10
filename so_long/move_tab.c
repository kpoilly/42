/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:50:18 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/10 19:26:20 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

//Déplace le P dans le tableau et effectue des verif (collectibles)
void	move_in_tab(t_global *global, char *dest, char *src)
{
	if (*dest == 'C' && global->nbcollec > 0)
	{
		global->nbcollec--;
		if (!global->nbcollec)
		{
			ft_printf("Hooray, you got all the Frogs !\n");
			check_end_game(global);
		}
	}
	if (*dest == 'E' && !global->nbcollec)
		end_the_game(global);
	else if (*dest == 'G')
		game_over(global);
	else if (*dest == '0' || *dest == 'C')
	{
		*dest = 'P';
		*src = '0';
		global->moves++;
		ft_printf("Moves : %d\n", global->moves);
	}
}

void	move_tab_up(t_global *global)
{
	int		x;
	int		y;

	y = 0;
	while (global->map[y])
	{
		x = 0;
		while (global->map[y][x])
		{
			if (global->map[y][x] == 'P')
				if (y && (global->map[y - 1][x] != '1'
					&& global->map[y - 1][x] != '2'
					&& global->map[y - 1][x] != '3'))
					return (move_in_tab(global, &(global->map[y - 1][x]),
						&(global->map[y][x])));
			x++;
		}
		y++;
	}
}

void	move_tab_down(t_global *global)
{
	int		x;
	int		y;

	y = 0;
	while (global->map[y])
	{
		x = 0;
		while (global->map[y][x])
		{
			if (global->map[y][x] == 'P')
				if (global->map[y + 1] && (global->map[y + 1][x] != '1'
					&& global->map[y + 1][x] != '2'
					&& global->map[y + 1][x] != '3'))
					return (move_in_tab(global, &(global->map[y + 1][x]),
						&(global->map[y][x])));
			x++;
		}
		y++;
	}
}

void	move_tab_right(t_global *global)
{
	int		x;
	int		y;

	y = 0;
	while (global->map[y])
	{
		x = 0;
		while (global->map[y][x])
		{
			if (global->map[y][x] == 'P')
				if (global->map[y][x + 1] && (global->map[y][x + 1] != '1' &&
					global->map[y][x + 1] != '2'
					&& global->map[y][x + 1] != '3'))
					return (move_in_tab(global, &(global->map[y][x + 1]),
						&(global->map[y][x])));
			x++;
		}
		y++;
	}
}

void	move_tab_left(t_global *global)
{
	int		x;
	int		y;

	y = 0;
	while (global->map[y])
	{
		x = 0;
		while (global->map[y][x])
		{
			if (global->map[y][x] == 'P')
				if (x && (global->map[y][x - 1] != '1'
					&& global->map[y][x - 1] != '2'
					&& global->map[y][x - 1] != '3'))
					return (move_in_tab(global, &(global->map[y][x - 1]),
						&(global->map[y][x])));
			x++;
		}
		y++;
	}
}
