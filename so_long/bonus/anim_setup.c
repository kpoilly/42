/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:42:45 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/04 12:24:05 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data/headers/so_long.h"

set_next(t_global *global)
{
	//truc qui va set up les next de chaque img
	//pour faire une rotation dans les imgs
	//donc une animation
	global->player.front.next = &global->player.back;
	global->player.back.next = &global->player.front;
}
