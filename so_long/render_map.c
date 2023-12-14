/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:18:07 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/14 17:28:49 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

//check quelle image il doit afficher
static void	check_item(t_global *global, t_img state, int x, int y)
{
	if (global->map[y][x] == '1')
	{	
		if (!y || !x || !global->map[y + 1] || !global->map[y][x + 1])
			put_img_to_img(global->bg, global->wallout, x * 50, y * 50);
		else
			put_img_to_img(global->bg, global->wallin, x * 50, y * 50);
	}
	if (global->map[y][x] == '0')
		put_img_to_img(global->bg, global->ground, x * 50, y * 50);
	if (global->map[y][x] == 'P')
	{
		put_img_to_img(global->bg, global->ground, x * 50, y * 50);
		put_img_to_img(global->bg, state, x * 50, (y * 50) - 20);
	}
	if (global->map[y][x] == 'C')
	{
		put_img_to_img(global->bg, global->ground, x * 50, y * 50);
		put_img_to_img(global->bg, global->collec, x * 50, y * 50);
	}
	if (global->map[y][x] == 'E')
	{
		put_img_to_img(global->bg, global->ground, x * 50, y * 50);
		put_img_to_img(global->bg, global->exit, x * 50, y * 50);
	}
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
}
