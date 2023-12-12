/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:15:47 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/12 15:51:05 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "./minilibx-linux/mlx.h"

typedef struct	s_window {
	void	*mlx;
	void	*win;
}				t_window;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_map(void *mlx, void *mlx_win, t_data	map, t_data	wall, t_data collec)
{

	char *mapp[] = {"111111111111111111111111",
				  	"102220000000001111100001",
				   	"102200010000001111100001",
				  	"102222010000000000100001",
				  	"111111110000000000000001",
				  	"100000000010000000000001",
				  	"100000000011100000100001",
				  	"100000000000000000100201",
				  	"100000000000021111111111",
					"100000000000000000000001",
				  	"100000000001000000000001",
				  	"100011111111000000000001",
					"100000100000000000000021",
				  	"100002100000000000111111",
				  	"100000100000000000000001",
					"111111111111111111111111", NULL};

	int w = 1; int h = 1;
	int i = 0; int j = 0; 
	int x = 1; int y = 1;

	while (mapp[i])
	{
		x = 1;
		j = 0;
		while (mapp[i][j])
		{
			if (mapp[i][j] == '1')
			{
				wall.img = mlx_xpm_file_to_image(mlx, "wallng.xpm", &w, &h);
				wall.addr = mlx_get_data_addr(wall.img, &wall.bits_per_pixel,
				 				&wall.line_length, &wall.endian);
				mlx_put_image_to_window(mlx, mlx_win, wall.img, x, y);
				mlx_destroy_image(mlx, wall.img);
			}
			else if (mapp[i][j] == '0')
			{
				map.img = mlx_xpm_file_to_image(mlx, "ground2ng.xpm", &w, &h);
				map.addr = mlx_get_data_addr(map.img, &map.bits_per_pixel,
								&map.line_length, &map.endian);
				mlx_put_image_to_window(mlx, mlx_win, map.img, x, y);
				mlx_destroy_image(mlx, map.img);
			}
			else if (mapp[i][j] == '2')
			{
				collec.img = mlx_xpm_file_to_image(mlx, "chestng.xpm", &w, &h);
				collec.addr = mlx_get_data_addr(collec.img, &collec.bits_per_pixel,
								&collec.line_length, &collec.endian);
				mlx_put_image_to_window(mlx, mlx_win, collec.img, x, y);
				mlx_destroy_image(mlx, collec.img);
			}
			j++;
			x += 50;
		}
		i++;
		y += 50;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_data	wall;
	t_data	map;
	t_data	collec;
	int ww = 1200; int wh = 800;
	int w = 1; int h = 1;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	mlx_win = mlx_new_window(mlx, ww, wh, "Oh woow !");

	img.img = mlx_xpm_file_to_image(mlx, "persopetitng.xpm", &w, &h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	draw_map(mlx, mlx_win, map, wall, collec);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 500, 400);

	mlx_loop(mlx);
}
