/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:50:18 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/15 17:07:44 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

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
			{
				if (y && global->map[y - 1][x] != '1')
				{
					global->map[y - 1][x] = 'P';
					global->map[y][x] = '0';
					global->moves++;
					ft_printf("Mouvements : %d\n", global->moves);
					return ;
				}
			}
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
			{
				if (global->map[y + 1] && global->map[y + 1][x] != '1')
				{
					global->map[y + 1][x] = 'P';
					global->map[y][x] = '0';
					global->moves++;
					ft_printf("Mouvements : %d\n", global->moves);
					return ;
				}
			}
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
			{
				if (global->map[y][x + 1] && global->map[y][x + 1] != '1')
				{
					global->map[y][x + 1] = 'P';
					global->map[y][x] = '0';
					global->moves++;
					ft_printf("Mouvements : %d\n", global->moves);
					return ;
				}
			}
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
			{
				if (x && global->map[y][x - 1] != '1')
				{
					global->map[y][x - 1] = 'P';
					global->map[y][x] = '0';
					global->moves++;
					ft_printf("Mouvements : %d\n", global->moves);
					return ;
				}
			}
			x++;
		}
		y++;
	}
}
