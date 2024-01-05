/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:42:45 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/05 09:17:45 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data/headers/so_long.h"

void	set_next(t_global *global)
{
	//truc qui va set up les next de chaque img
	//pour faire une rotation dans les imgs
	//donc une animation
	global->player.front.next = &global->player.front2;
	global->player.front2.next = &global->player.front;
	global->player.back.next = &global->player.back2;
	global->player.back2.next = &global->player.back;
	global->player.right.next = &global->player.right2;
	global->player.right2.next = &global->player.right;
	global->player.left.next = &global->player.left2;
	global->player.left2.next = &global->player.left;
}

void	set_paths_anim(t_global *global)
{
	global->player.paths.front2 = "./data/textures/perso_face2.xpm";
	global->player.paths.back2 = "./data/textures/perso_dos2.xpm";
	global->player.paths.right2 = "./data/textures/perso_droit2.xpm";
	global->player.paths.left2 = "./data/textures/perso_gauche2.xpm";
	//pareil pour enemy;
}
