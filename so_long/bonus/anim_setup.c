/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:42:45 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/04 17:29:55 by kpoilly          ###   ########.fr       */
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

	global->player.back.next = &global->wallin;
	global->wallin.next = &global->player.back;

	global->player.right.next = &global->wallin;
	global->wallin.next = &global->player.right;

	global->player.left.next = &global->wallout.front;
	global->wallout.front.next = &global->player.left;
}
