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
int	open_exit(t_global *global)
{
	int	h;
	int	w;

	h = 50;
	w = 50;
	mlx_destroy_image(global->mlx.ptr, global->exit.img);
	global->exit.img = mlx_xpm_file_to_image(global->mlx.ptr,
			"./data/textures/exit00.xpm", &w, &h);
	if (!global->exit.img)
		return (ft_printf("Error.\nMissing Texture files.\n"),
			destroy(global), 0);
	global->exit.addr = mlx_get_data_addr(global->exit.img,
			&(global->exit.bits_per_pixel),
			&(global->exit.line_len), &(global->exit.endian));
	return (1);
}

//Check si tous les collectibles ont été ramassés
void	check_end_game(t_global *global)
{
	if (!global->nbcollec)
		open_exit(global);
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
		(global->mlx.width / 2) - w / 2, (global->mlx.height / 2) - h / 2);
	ft_printf("Game Over !\n");
	i = 0;
	while (i++ < 5000)
		mlx_put_image_to_window(global->mlx.ptr, global->mlx.win,
			global->bg.img, 0, 0);
	mlx_destroy_image(global->mlx.ptr, gameover.img);
	destroy(global);
}
