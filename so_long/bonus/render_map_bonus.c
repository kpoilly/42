/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:18:07 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/25 10:17:19 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data/headers/so_long.h"

//Affiche le nombre de mouvements dans la window (BONUS)
void	putnbr_mouvements(t_global *global)
{
	putnbr_window(global, global->moves,
		global->mlx.width - 70, global->mlx.height - 30);
	put_img_to_img(global->bg, global->wallin.back2,
		global->mlx.width - 45, global->mlx.height - 33);
}

//Affiche le nombre de collectibles restants dans la window
static void	putnbr_collectibles(t_global *global)
{
	putnbr_window(global, global->nbcollec,
		(global->mlx.width / 2) - 10, global->mlx.height - 30);
	put_img_to_img(global->bg, global->wallin.front2,
		(global->mlx.width / 2) + 15, global->mlx.height - 27);
}

//check quel mur il doit afficher
static void	render_wall(t_global *global, int x, int y)
{
	if (!y)
		put_img_to_img(global->bg, global->wallout.front, x * 50 - 5, y * 50);
	else if (!global->map[y + 1])
		put_img_to_img(global->bg, global->wallout.back, x * 50 - 5,
			y * 50 - 35);
	else if (!x)
		put_img_to_img(global->bg, global->wallout.left, x * 50, y * 50 - 35);
	else if (!global->map[y][x + 1])
		put_img_to_img(global->bg, global->wallout.right, x * 50, y * 50 - 35);
	else
	{
		if (global->map[y][x] == '1')
			put_img_to_img(global->bg, global->wallin.front, x * 50,
				y * 50);
		else if (global->map[y][x] == '2')
			put_img_to_img(global->bg, global->wallin.back, x * 50,
				y * 50 - 5);
		else if (global->map[y][x] == '3')
			put_img_to_img(global->bg, global->wallin.left, x * 50,
				y * 50 - 5);
	}
}

//check quelle image il doit afficher
static void	check_item(t_global *global, t_img state, int x, int y)
{
	put_img_to_img(global->bg, global->ground, x * 50, y * 50);
	if (global->map[y][x] == '1'
		|| global->map[y][x] == '2' || global->map[y][x] == '3')
		render_wall(global, x, y);
	else if (global->map[y][x] == 'P')
		put_img_to_img(global->bg, state, x * 50, (y * 50) - 20);
	else if (global->map[y][x] == 'C')
		put_img_to_img(global->bg, global->collec, x * 50, y * 50);
	else if (global->map[y][x] == 'E')
		put_img_to_img(global->bg, global->exit, x * 50 - 25, y * 50 - 25);
	else if (global->map[y][x] == 'G')
		put_img_to_img(global->bg, global->enemy.last_state, x * 50 -10,
			y * 50 - 40);
	global->player.last_state = state;
}

//Parcours la char**map et affiche les images aux bons endroits
void	render_map(t_global *global, t_img state)
{
	int	x;
	int	y;

	y = 0;
	while (global->map[y])
	{
		x = 0;
		while (global->map[y][x])
		{
			check_item(global, state, x, y);
			x++;
		}
		y++;
	}
	putnbr_mouvements(global);
	putnbr_collectibles(global);
	mlx_put_image_to_window(global->mlx.ptr, global->mlx.win,
		global->bg.img, 0, 0);
	putstr_endgame(global);
}
