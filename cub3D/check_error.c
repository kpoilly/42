/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:57:03 by lleciak           #+#    #+#             */
/*   Updated: 2024/03/28 10:06:32 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/headers/cub3D.h"

//check if the color is in the [0, 255] limit
int	check_colors(t_data *data)
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
int	check_textures(t_data *data)
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
	if (check != 4)
		return (ft_printf(2, "Error.\nInvalid texture path.\n"), 0);
	return (1);
}

int	check_error(t_data *data, char **map)
{
	if (!check_textures(data) || !check_colors(data) || !map)
		return (0);
	return (1);
}

//map is a .cub
int	map_format(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] && arg[i] != '.')
		i++;
	i++;
	if (arg[i] && arg[i] == 'c' && arg[i + 1] && arg[i + 1] == 'u' && arg[i + 2]
		&& arg[i + 2] == 'b' && !arg[i + 3])
		return (1);
	return (ft_printf(2, "Error.\nMap is not a .cub\n"), 0);
}
