/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:42:45 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/15 13:18:55 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data/headers/so_long.h"

//set les listes circulaires pour les anim
void	set_next(t_global *global)
{
	global->player.front.next = &global->player.front2;
	global->player.front2.next = &global->player.front;
	global->player.back.next = &global->player.back2;
	global->player.back2.next = &global->player.back;
	global->player.right.next = &global->player.right2;
	global->player.right2.next = &global->player.right;
	global->player.left.next = &global->player.left2;
	global->player.left2.next = &global->player.left;
}

//set les paths des xpm qui servent aux anims
void	set_paths_anim(t_global *global)
{
	global->player.paths.front2 = "./data/textures/perso_face2.xpm";
	global->player.paths.back2 = "./data/textures/perso_dos2.xpm";
	global->player.paths.right2 = "./data/textures/perso_droit2.xpm";
	global->player.paths.left2 = "./data/textures/perso_gauche2.xpm";
	//pareil pour enemy;
}

//affiche une image sur toute la window avec un fond noir (anim)
void	putimg(t_global *global, t_img img)
{
	load_blackscreen(global);
	put_img_to_img(global->bg, img, (global->mlx.width / 2) - img.w / 2,
		(global->mlx.height / 2) - img.h / 2);
	mlx_put_image_to_window(global->mlx.ptr, global->mlx.win,
		global->bg.img, 0, 0);
}
