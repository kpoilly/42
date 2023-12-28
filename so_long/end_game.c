/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:07:50 by marvin            #+#    #+#             */
/*   Updated: 2023/12/17 16:07:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

//Charge l'image de la sortie "ouverte"
static void	open_exit(t_global *global)
{
	(void)global;
	//changer le path de exit pour exit2.xpm
	//charger l'xpm de la nouvelle sortie
}

void	putstr_endgame(t_global *global)
{
	if (!global->nbcollec)
		mlx_string_put(global->mlx.ptr, global->mlx.win,
			global->mlx.width - (global->mlx.width / 2) - 100,
			global->mlx.height - (global->mlx.height / 2), (int)0x00FF00FF,
			"GOBLINOU IS COMING FOR YOU, HURRY UP !");
}

//Check si tous les collectibles ont été ramassés
void	check_end_game(t_global *global)
{
	if (!global->nbcollec)
		open_exit(global);
	//animation danse (a voir hein)
}

//Ferme le jeu (Voir pour animation ou écran de fin avant)
void	end_the_game(t_global *global)
{
	ft_printf("Congrats!\nThanks for playing !\n");
	destroy(0, global);
}

void	game_over(t_global *global)
{
	printf("GAME OVER!");
	destroy(0, global);
}
