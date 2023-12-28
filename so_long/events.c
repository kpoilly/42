/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:31:14 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/28 13:47:29 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

//Actions en fonction de la touche pressée
int	keypress(int keycode, t_global *global)
{
	if (keycode == 65362 || keycode == 119)
		return (move_tab_up(global), ennemy_move(global),
			render_map(global, global->player.back), 1);
	else if (keycode == 65364 || keycode == 115)
		return (move_tab_down(global), ennemy_move(global),
			render_map(global, global->player.front), 1);
	else if (keycode == 65361 || keycode == 97)
		return (move_tab_left(global), ennemy_move(global),
			render_map(global, global->player.left), 1);
	else if (keycode == 65363 || keycode == 100)
		return (move_tab_right(global), ennemy_move(global),
			render_map(global, global->player.right), 1);
	else if (keycode == 65307)
		destroy(0, global);
	return (0);
}

//Fonction qui tourne quand on ne presse rien (respiration ?)
int	no_event(t_global *global)
{
	(void)global;
	// ennemy_move(global);
	// usleep(200000);
	// render_map(global, global->player_dos);
	return (0);
}

//Ferme la window de façon propre
int	destroy(int keycode, t_global *global)
{
	(void)keycode;
	mlx_destroy_window(global->mlx.ptr, global->mlx.win);
	exit(0);
	//mlx_destroy_display(global->mlx.ptr);
	//free(global->mlx.ptr);
	//exit(0);
	//reste a free chaque truc, donc toutes les addr des img
	//une par une, voir pour les mettre dans un tableau ou
	//liste chainee ou autre
	return (0);
}
