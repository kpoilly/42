/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:25:57 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/24 15:57:47 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data/headers/so_long.h"

static void	free_enemy(t_global *global)
{
	if (global->enemy.front.img)
		mlx_destroy_image(global->mlx.ptr, global->enemy.front.img);
	if (global->enemy.back.img)
		mlx_destroy_image(global->mlx.ptr, global->enemy.back.img);
	if (global->enemy.right.img)
		mlx_destroy_image(global->mlx.ptr, global->enemy.right.img);
	if (global->enemy.left.img)
		mlx_destroy_image(global->mlx.ptr, global->enemy.left.img);
	if (global->enemy.front2.img)
		mlx_destroy_image(global->mlx.ptr, global->enemy.front2.img);
	if (global->enemy.back2.img)
		mlx_destroy_image(global->mlx.ptr, global->enemy.back2.img);
	if (global->enemy.right2.img)
		mlx_destroy_image(global->mlx.ptr, global->enemy.right2.img);
	if (global->enemy.left2.img)
		mlx_destroy_image(global->mlx.ptr, global->enemy.left2.img);
}

static void	free_player_anim(t_global *global)
{
	if (global->player.front2.img)
		mlx_destroy_image(global->mlx.ptr, global->player.front2.img);
	if (global->player.back2.img)
		mlx_destroy_image(global->mlx.ptr, global->player.back2.img);
	if (global->player.right2.img)
		mlx_destroy_image(global->mlx.ptr, global->player.right2.img);
	if (global->player.left2.img)
		mlx_destroy_image(global->mlx.ptr, global->player.left2.img);
}

void	free_anim(t_global *global)
{
	if (global->wallin.front2.img)
		mlx_destroy_image(global->mlx.ptr, global->wallin.front2.img);
	if (global->wallin.back2.img)
		mlx_destroy_image(global->mlx.ptr, global->wallin.back2.img);
}

void	free_numbers(t_global *global)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (global->numbers[i].img)
			mlx_destroy_image(global->mlx.ptr, global->numbers[i].img);
		i++;
	}
}

void	free_bonus(t_global *global)
{
	free_enemy(global);
	free_anim(global);
	free_player_anim(global);
}
