/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:54:32 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/14 17:29:39 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

//fonction qui tourne quand on ne presse rien
int	no_event(void)
{
	return (0);
}

//tentative pour gerer la croix pour fermer
int	destroy(int keycode, t_global *global)
{
	mlx_destroy_window(global->mlx.ptr, global->mlx.win);
	//mlx_destroy_display(global->mlx.ptr);
	//free(global->mlx.ptr);
	//exit(0);
	//reste a free chaque truc, donc toutes les addr des img
	//une par une, voir pour les mettre dans un tableau ou
	//liste chainee ou autre
	return (0);
}

//test des keypress
int	keypress(int keycode, t_global *global)
{
	if (keycode == 65362 || keycode == 119)
	{
		render_map(global, global->player_dos);
		mlx_put_image_to_window(global->mlx.ptr, global->mlx.win,
			global->bg.img, 0, 0);
	}
	if (keycode == 65364 || keycode == 115)
	{
		render_map(global, global->player_face);
		mlx_put_image_to_window(global->mlx.ptr, global->mlx.win,
			global->bg.img, 0, 0);
	}
	if (keycode == 65361 || keycode == 97)
	{
		render_map(global, global->player_gauche);
		mlx_put_image_to_window(global->mlx.ptr, global->mlx.win,
			global->bg.img, 0, 0);
	}
	if (keycode == 65363 || keycode == 100)
	{
		render_map(global, global->player_droit);
		mlx_put_image_to_window(global->mlx.ptr, global->mlx.win,
			global->bg.img, 0, 0);
	}
	if (keycode == 65307)
	{
		mlx_destroy_window(global->mlx.ptr, global->mlx.win);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int			fd;
	int			nb_line;
	int			nb_col;
	t_global	global;

	// if (argc < 2)
	// {
	// 	printf("No map given.\n");
	// 	return (0);
	// }
	//global.map = check_error(get_map(argv[1], &nb_line, &nb_col));
	// if (!global.map)
	// 	return (0);
	if (!set_global(&global, 19, 12)) //remplacer par nbcol et nbline
		return (0);
	// if (!so_long(&global))
	// 	return (0);

	//tests random :
	char *mapp[] = {"1111111111111111111",
				  	"10CCC00000000011111",
				   	"10CC000100000011111",
				  	"10CCCC0100000000001",
				  	"1111111100000000001",
				  	"1000000000100000001",
				  	"1000000000111000001",
				  	"10000000000P0000001",
				  	"1000000000000C11111",
					"1000000000000000001",
				  	"10000C00000100000E1",
					"1111111111111111111", NULL};
	global.map = mapp;
	render_map(&global, global.player_face);
	mlx_put_image_to_window(global.mlx.ptr, global.mlx.win,
		global.bg.img, 0, 0);
	mlx_loop_hook(global.mlx.ptr, &no_event, &global);
	mlx_hook(global.mlx.win, 2, 1L << 0, &keypress, &global);
	mlx_hook(global.mlx.win, 17, 1L << 17, &destroy, &global);
	mlx_loop(global.mlx.ptr);
	//mlx_destroy_display(global.mlx.ptr);
	return (0);
}
