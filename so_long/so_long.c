/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:54:32 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/02 14:31:26 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

int	main(int argc, char **argv)
{
	int			nb_line;
	int			nb_col;
	t_global	global;

	if (argc < 2)
		return (ft_printf("Error.\nNo map given.\n"), 0);
	global.map = check_error(get_map(argv[1], &nb_line, &nb_col), &global);
	if (!global.map)
		return (0);
	if (!set_global(&global, nb_col, nb_line))
		return (ft_printf("Error.\n"), destroy(&global), 0);
	spawn_ennemy(&global, nb_line, nb_col);
	render_map(&global, global.player.front);
	mlx_hook(global.mlx.win, 2, 1L << 0, &keypress, &global);
	mlx_hook(global.mlx.win, 17, 1L << 17, &destroy, &global);
	mlx_loop_hook(global.mlx.ptr, &no_event, &global);
	mlx_loop(global.mlx.ptr);
	mlx_destroy_display(global.mlx.ptr);
	return (0);
}
