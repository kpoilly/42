/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:57:03 by lleciak           #+#    #+#             */
/*   Updated: 2024/04/18 13:41:54 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/headers/cub3D.h"

// is the map valid ?
static int	valid_map(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((y == 0 && map[y][x] != '1' && map[y][x] != ' ')
				|| (x == 0 && map[y][x] != '1' && map[y][x] != ' ')
				|| (!map[y + 1] && map[y][x] != ' ' && map[y][x] != '1')
				|| (!map[y][x + 1] && map[y][x] != ' ' && map[y][x] != '1'))
				return (ft_printf(2, "Error.\nInvalid map.\n"), 0);
			else if (map[y][x] == '0'
				&& (y && map[y + 1] && x && map[y][x + 1])
				&& (!map_charset(map[y + 1][x]) || !map_charset(map[y - 1][x])
				|| !map_charset(map[y][x + 1]) || !map_charset(map[y][x - 1])))
				return (ft_printf(2, "Error.\nInvalid map.\n"), 0);
			x++;
		}
		y++;
	}
	return (1);
}

//check if the color is in the [0, 255] limit
static int	check_colors(t_data *data)
{
	int	i;

	if (!data->floor_colors || !data->ceiling_colors)
		return (ft_printf(2, "Error.\nInvalid RGB number.\n"), 0);
	i = 0;
	while (i < 3)
	{
		if (data->floor_colors[i] < 0 || data->floor_colors[i] > 255
			|| data->ceiling_colors[i] < 0 || data->ceiling_colors[i] > 255)
			return (ft_printf(2, "Error.\nInvalid RGB number.\n"), 0);
		i++;
	}
	return (1);
}

//did the img load ? texture exist ?
static int	check_textures(t_data *data)
{
	int	check;

	if (!data->no_text || !data->so_text
		|| !data->we_text || !data->ea_text)
		return (ft_printf(2, "Error.\nInvalid texture path.\n"), 0);
	check = 0;
	check += load_texture(data, &data->no, data->no_text);
	check += load_texture(data, &data->so, data->so_text);
	check += load_texture(data, &data->we, data->we_text);
	check += load_texture(data, &data->ea, data->ea_text);
	check += load_texture(data, &data->micro.hand,
			"./utils/textures/TABLETTEV2.xpm");
	if (check != 5)
		return (ft_printf(2, "Error.\nInvalid texture path.\n"), 0);
	return (1);
}

int	check_error(t_data *data, char **map)
{
	if (!check_textures(data) || !check_colors(data) || !map || !valid_map(map))
		return (0);
	return (1);
}

//map is a .cub
int	map_format(char *arg)
{
	int	i;

	i = ft_strlen(arg) - 1;
	while (arg[i] && arg[i] != '.')
		i--;
	i++;
	if (arg[i] && arg[i] == 'c' && arg[i + 1] && arg[i + 1] == 'u' && arg[i + 2]
		&& arg[i + 2] == 'b' && !arg[i + 3])
		return (1);
	return (ft_printf(2, "Error.\nMap is not a .cub\n"), 0);
}
