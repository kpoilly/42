/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:19:47 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/05 14:44:06 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

void	free_player(t_global *global)
{
	if (global->player.front.img)
		mlx_destroy_image(global->mlx.ptr, global->player.front.img);
	if (global->player.back.img)
		mlx_destroy_image(global->mlx.ptr, global->player.back.img);
	if (global->player.right.img)
		mlx_destroy_image(global->mlx.ptr, global->player.right.img);
	if (global->player.left.img)
		mlx_destroy_image(global->mlx.ptr, global->player.left.img);
}

void	free_images(t_global *global)
{
	if (global->bg.img)
		mlx_destroy_image(global->mlx.ptr, global->bg.img);
	if (global->collec.img)
		mlx_destroy_image(global->mlx.ptr, global->collec.img);
	if (global->ground.img)
		mlx_destroy_image(global->mlx.ptr, global->ground.img);
	if (global->exit.img)
		mlx_destroy_image(global->mlx.ptr, global->exit.img);
	if (global->wallin.img)
		mlx_destroy_image(global->mlx.ptr, global->wallin.img);
	if (global->wallout.front.img)
		mlx_destroy_image(global->mlx.ptr, global->wallout.front.img);
	if (global->wallout.back.img)
		mlx_destroy_image(global->mlx.ptr, global->wallout.back.img);
	if (global->wallout.right.img)
		mlx_destroy_image(global->mlx.ptr, global->wallout.right.img);
	if (global->wallout.left.img)
		mlx_destroy_image(global->mlx.ptr, global->wallout.left.img);
	free_player(global);
}

void	free_the_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}
