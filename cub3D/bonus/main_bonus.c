/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 08:41:46 by lleciak           #+#    #+#             */
/*   Updated: 2024/09/17 19:32:38 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/cub3D.h"

void	free_text_extra(t_data *data)
{
	if (data->micro.hand.img)
		mlx_destroy_image(data->mlx.ptr, data->micro.hand.img);
	if (data->lol.img)
		mlx_destroy_image(data->mlx.ptr, data->lol.img);
	if (data->crocs.img)
		mlx_destroy_image(data->mlx.ptr, data->crocs.img);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_printf(2, "Error.\nInvalid argument.\n"), 1);
	if (!map_format(argv[1]))
		exit(1);
	data.mlx.ptr = mlx_init();
	if (!data.mlx.ptr)
		return (ft_printf(2, "Error.\n(mlx init)\n"), exit(1), 1);
	set_up_img(&data);
	data.map = read_map(&data, argv[1]);
	if (!data.map)
		return (1);
	set_up(&data);
	data.mlx.win = mlx_new_window(data.mlx.ptr, SC_W, SC_H, "Cub3D :]");
	if (!data.mlx.win)
		return (ft_printf(2, "Error.\n(mlx win setup)\n"), exit(1), 1);
	draw_bg(&data);
	mlx_mouse_hide(data.mlx.ptr, data.mlx.win);
	mlx_loop_hook(data.mlx.ptr, &no_event, &data);
	mlx_hook(data.mlx.win, 17, 1L << 17, &destroy, &data);
	mlx_hook(data.mlx.win, 2, 1L << 0, &keypress, &data);
	mlx_hook(data.mlx.win, 3, 1L << 1, &keyrelease, &data);
	mlx_loop(data.mlx.ptr);
	return (mlx_destroy_display(data.mlx.ptr), 0);
}
