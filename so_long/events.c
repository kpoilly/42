/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:31:14 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/03 15:59:23 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

//Actions en fonction de la touche pressée
int	keypress(int keycode, t_global *global)
{
	if (keycode == 65362 || keycode == 119)
		return (move_tab_up(global),
			render_map(global, global->player.back), 1);
	else if (keycode == 65364 || keycode == 115)
		return (move_tab_down(global),
			render_map(global, global->player.front), 1);
	else if (keycode == 65361 || keycode == 97)
		return (move_tab_left(global),
			render_map(global, global->player.left), 1);
	else if (keycode == 65363 || keycode == 100)
		return (move_tab_right(global),
			render_map(global, global->player.right), 1);
	else if (keycode == 65307)
		destroy(global);
	return (0);
}

//Fonction qui tourne quand on ne presse rien (respiration ?)
int	no_event(t_global *global)
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
		ennemy_move(global);
		render_map(global, global->last_state);
	}
	return (0);
}

//Ferme la window de façon propre
int	destroy(t_global *global)
{
	free_images(global);
	free_the_map(global->map);
	mlx_destroy_window(global->mlx.ptr, global->mlx.win);
	mlx_destroy_display(global->mlx.ptr);
	free(global->mlx.ptr);
	exit(0);
	return (0);
}
