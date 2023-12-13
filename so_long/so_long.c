/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:54:32 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/13 16:35:30 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/so_long.h"

int	so_long(char **map, int width, int height)
{
	t_mlx	mlx;

	mlx.ptr = mlx_init();
	if (!mlx.ptr)
		return (0);
	mlx.win = mlx_new_window(mlx.ptr, width, height, "Catch the Frogs !");
	mlx_loop(mlx.ptr);
	mlx_destroy_window(mlx.ptr, mlx.win);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	**map;
	int		nb_line;
	int		nb_col;

	if (argc < 2)
	{
		ft_printf("No map given.\n");
		return (0);
	}
	map = check_error(get_map(argv[1], &nb_line, &nb_col));
	if (!map)
		return (0);
	if (!so_long(map, nb_col * 50, nb_line * 50))
		return (0);
}
