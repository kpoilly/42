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

#include "../data/headers/so_long.h"

//Charge l'image de la sortie "ouverte"
static void	open_exit(t_global *global)
{
	int		i;
	t_img	black;

	//destroy exit
	//charger l'xpm de la nouvelle sortie dans exit
	black.img = mlx_new_image(global->mlx.ptr,
			global->mlx.width, global->mlx.height);
	i = 0;
	while (i++ < 10000)
		mlx_put_image_to_window(global->mlx.ptr, global->mlx.win,
			black.img, 0, 0);
}

//Dit au joueur de se grouiller
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
		//animation danse
}

//Ferme le jeu (Voir pour animation ou écran de fin avant)
void	end_the_game(t_global *global)
{
	ft_printf("Congrats!\nThanks for playing !\n");
	destroy(global);
}

//Affiche Game over et quitte proprement le programme
void	game_over(t_global *global)
{
	int		w;
	int		h;
	int		i;
	t_img	gameover;

	w = 300;
	h = 150;
	gameover.img = mlx_xpm_file_to_image(global->mlx.ptr,
			"./data/textures/gameover.xpm", &w, &h);
	if (!gameover.img)
		return (ft_printf("Error.\nMissing Texture files.\n"),
			(void)destroy(global));
	gameover.addr = mlx_get_data_addr(gameover.img, &(gameover.bits_per_pixel),
			&(gameover.line_len), &(gameover.endian));
	gameover.w = w;
	gameover.h = h;
	put_img_to_img(global->bg, gameover,
		(global->mlx.width / 2) - 150, (global->mlx.height / 2) - 75);
	ft_printf("Game Over !\n");
	i = 0;
	while (i++ < 8000)
		mlx_put_image_to_window(global->mlx.ptr, global->mlx.win,
			global->bg.img, 0, 0);
	mlx_destroy_image(global->mlx.ptr, gameover.img);
	destroy(global);
}