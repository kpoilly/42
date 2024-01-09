/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:18:07 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/04 20:00:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data/headers/so_long.h"

//Affiche le nombre de mouvements dans la window (BONUS)
void	putnbr_mouvements(t_global *global)
{
	char	*str;

	str = ft_itoa(global->moves);
	mlx_string_put(global->mlx.ptr, global->mlx.win, global->mlx.width - 125,
		global->mlx.height - 22, (int)0x00CCFFFF, "Moves : ");
	mlx_string_put(global->mlx.ptr, global->mlx.win, global->mlx.width - 70,
		global->mlx.height - 22, (int)0x00CCFFFF, str);
	free(str);
}

//Affiche le nombre de collectibles restants dans la window
static void	putnbr_collectibles(t_global *global)
{
	char	*str;

	str = ft_itoa(global->nbcollec);
	mlx_string_put(global->mlx.ptr, global->mlx.win,
		global->mlx.width - (global->mlx.width / 2) - 50,
		global->mlx.height - 22, (int)0x00CCFFFF, "Remaining frogs : ");
	mlx_string_put(global->mlx.ptr, global->mlx.win,
		global->mlx.width - (global->mlx.width / 2) + 75,
		global->mlx.height - 22, (int)0x00CCFFFF, str);
	free(str);
}

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
		put_img_to_img(global->bg, global->wallin, x * 50 - 10, y * 50 - 10);
}

//check quelle image il doit afficher
static void	check_item(t_global *global, t_img state, int x, int y)
{
	put_img_to_img(global->bg, global->ground, x * 50, y * 50);
	if (global->map[y][x] == '1')
		render_wall(global, x, y);
	else if (global->map[y][x] == 'P')
		put_img_to_img(global->bg, state, x * 50, (y * 50) - 20);
	else if (global->map[y][x] == 'C')
		put_img_to_img(global->bg, global->collec, x * 50, y * 50 + 10);
	else if (global->map[y][x] == 'E')
		put_img_to_img(global->bg, global->exit, x * 50, y * 50);
	else if (global->map[y][x] == 'G')
		put_img_to_img(global->bg, global->enemy.front, x * 50 -10,
			y * 50 - 40);
	global->player.last_state = state;
	//global->ennemy.last_state = en_state;
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
	mlx_put_image_to_window(global->mlx.ptr, global->mlx.win,
		global->bg.img, 0, 0);
	putnbr_mouvements(global);
	putnbr_collectibles(global);
	putstr_endgame(global);
}