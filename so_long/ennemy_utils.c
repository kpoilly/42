/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemy_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:11:38 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/28 18:56:21 by kpoilly          ###   ########.fr       */
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

//Recupere la coordonne du joueur dans la map
void	get_target(t_global *global, int *x, int *y)
{
	*x = 0;
	*y = 0;
	while (global->map[*y])
	{
		*x = 0;
		while (global->map[*y][*x])
		{
			if (global->map[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

//Verifie si le joueur se trouve dans la range de vision de l'ennemi
int	in_range(int player_x, int player_y, int x, int y)
{
	return ((player_x >= x - 3 && player_x <= x + 3)
		&& (player_y >= y - 3 && player_y <= y + 3));
}

//L'ennemi cherche un chemin de parcours pour se rapprocher du milieu
void	find_path(t_global *global, int x, int y)
{
	if (global->player.x >= ((global->mlx.width / 50) / 2)
		&& x <= ((global->mlx.width / 50) / 2))
		return (search_right(global, x, y));
	else if (global->player.x < ((global->mlx.width / 50) / 2)
		&& x > ((global->mlx.width / 50) / 2))
		return (search_left(global, x, y));
	else if (global->player.y >= ((global->mlx.height / 50) / 2)
		&& y <= ((global->mlx.height / 50) / 2))
		return (search_down(global, x, y));
	else if (global->player.y < ((global->mlx.height / 50) / 2)
		&& y > ((global->mlx.height / 50) / 2))
		return (search_up(global, x, y));
	else
		return (patrol(global, x, y));
}

//choisi la direction du gobelin en fonction de si le joueur est dans sa range
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
