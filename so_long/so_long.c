/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:54:32 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/15 16:36:50 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

int	main(int argc, char **argv)
{
	int			nb_line;
	int			nb_col;
	t_global	global;

	if (argc < 2)
	{
		printf("No map given.\n");
		return (0);
	}
	global.map = check_error(get_map(argv[1], &nb_line, &nb_col));
	if (!global.map)
		return (0);

	if (!set_global(&global, nb_col, nb_line))
		return (0);
	render_map(&global, global.player_face);
	mlx_loop_hook(global.mlx.ptr, &no_event, &global);
	mlx_hook(global.mlx.win, 2, 1L << 0, &keypress, &global);
	mlx_hook(global.mlx.win, 17, 1L << 17, &destroy, &global);
	mlx_loop(global.mlx.ptr);
	mlx_destroy_display(global.mlx.ptr);
	return (0);
}
