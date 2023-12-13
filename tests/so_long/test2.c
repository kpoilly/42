/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:15:47 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/13 16:24:14 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
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
	int		w;
	int		h;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_pixel(t_data img, int x, int y)
{
	return (*(unsigned int *)(
		(img.addr + (y * img.line_length) + (x * img.bits_per_pixel / 8))));
}

void	put_pixel(t_data img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
		*(unsigned int *) dst = color;
	}
}

void	put_img_to_img(t_data dst, t_data src, int x, int y)
{
	int	j;
	int	i;

	i = 0;
	while (i < src.w)
	{
		j = 0;
		while (j < src.h)
		{
			put_pixel(dst, x + i, y + j, get_pixel(src, i, j));
			j++;
		}
		i++;
	}
}

char	*move_player(char *line)
{
	int len = 0;
	char *dest;

	while (line[len])
		len++;
	dest = malloc((len + 1) * sizeof(char));
	len = 0;
	while (line[len])
	{
		if (line[len] == 'P' && line[len + 1] && line[len + 1] == '0')
		{
			dest[len] = '0';
			dest[len + 1] = 'P';
			len++;
		}
		else
			dest[len] = line[len];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

int	draw_map(t_data base, char **mapp, void *mlx, void *mlx_win, t_data	map, t_data	wall, t_data collec)
{
	int w = 1; int h = 1;
	int i = 0; int j = 0; 
	int x = 1; int y = 1;
	int toret = 0;
	t_data	img;

	while (mapp[i])
	{
		x = 0;
		j = 0;
		while (mapp[i][j])
		{
			char *wallinout;
			if (mapp[i][j] == '1')
			{
				map.img = mlx_xpm_file_to_image(mlx, "ground2ng.xpm", &w, &h);
				map.addr = mlx_get_data_addr(map.img, &map.bits_per_pixel,
								&map.line_length, &map.endian);
				map.w = 50;
				map.h = 50;
				put_img_to_img(base, map, x, y);
				mlx_destroy_image(mlx, map.img);
				if (!i || !j || !mapp[i + 1] || !mapp[i][j + 1])
					wallinout = "wallng.xpm";
				else
					wallinout = "wallng.xpm";
				wall.img = mlx_xpm_file_to_image(mlx, wallinout, &w, &h);
				wall.addr = mlx_get_data_addr(wall.img, &wall.bits_per_pixel,
				 				&wall.line_length, &wall.endian);
				wall.w = 50;
				wall.h = 50;
				put_img_to_img(base, wall, x, y);
				mlx_destroy_image(mlx, wall.img);
			}
			else if (mapp[i][j] == '0')
			{
				map.img = mlx_xpm_file_to_image(mlx, "ground2ng.xpm", &w, &h);
				map.addr = mlx_get_data_addr(map.img, &map.bits_per_pixel,
								&map.line_length, &map.endian);
				map.w = 50;
				map.h = 50;
				put_img_to_img(base, map, x, y);
				mlx_destroy_image(mlx, map.img);
			}
			else if (mapp[i][j] == 'C')
			{
				collec.img = mlx_xpm_file_to_image(mlx, "chestng.xpm", &w, &h);
				collec.addr = mlx_get_data_addr(collec.img, &collec.bits_per_pixel,
								&collec.line_length, &collec.endian);
				collec.w = 50;
				collec.h = 50;
				put_img_to_img(base, collec, x, y);
				mlx_destroy_image(mlx, collec.img);
			}
			else if (mapp[i][j] == 'P')
			{
				map.img = mlx_xpm_file_to_image(mlx, "ground2ng.xpm", &w, &h);
				map.addr = mlx_get_data_addr(map.img, &map.bits_per_pixel,
								&map.line_length, &map.endian);
				map.w = 50;
				map.h = 50;
				put_img_to_img(base, map, x, y);
				mlx_destroy_image(mlx, map.img);
				img.img = mlx_xpm_file_to_image(mlx, "perso_facepetit.xpm", &w, &h);
				img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
					&img.line_length, &img.endian);
				img.w = 50;
				img.h = 70;
				put_img_to_img(base, img, x, y - 20);
				mlx_destroy_image(mlx, img.img);
				toret = i;
			}
			j++;
			x += 50;
		}
		i++;
		y += 50;
	}
	return (toret);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	base;
	t_data	wall;
	t_data	map;
	t_data	collec;
	int ww = 1200; int wh = 800;
	int w = 1; int h = 1;
	int line = 0;

	char *mapp[] = {"111111111111111111111111",
				  	"10CCC0000000001111100001",
				   	"10CC00010000001111100001",
				  	"10CCCC010000000000100001",
				  	"111111110000000000000001",
				  	"100000000010000000000001",
				  	"100000000011100000100001",
				  	"1P0000000000000000100C01",
				  	"1000000000000C1111111111",
					"100000000000000000000001",
				  	"100000000001000000000001",
				  	"100011111111000000000001",
					"1000001000000000000000C1",
				  	"10000C100000000000111111",
				  	"100000100000000000000001",
					"111111111111111111111111", NULL};

	mlx = mlx_init();
	if (!mlx)
		return (1);
	mlx_win = mlx_new_window(mlx, ww, wh, "Oh woow !");
	base.img = mlx_new_image(mlx, ww, wh);
	base.addr = mlx_get_data_addr(base.img, &base.bits_per_pixel,
			&base.line_length, &base.endian);
	base.w = 1200;
	base.h = 800;
	int i = 0; int j = 0;
	while (i < 11)
	{
		line = draw_map(base, mapp, mlx, mlx_win, map, wall, collec);
		mlx_put_image_to_window(mlx, mlx_win, base.img, 0, 0);
		while (j++ < 275)
			mlx_put_image_to_window(mlx, mlx_win, base.img, 0, 0);
		j = 0;
		mapp[line] = move_player(mapp[line]);
		i++;
	}
	mlx_loop(mlx);
}
