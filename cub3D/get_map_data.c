/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:04:57 by kpoilly           #+#    #+#             */
/*   Updated: 2024/09/17 18:12:00 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/headers/cub3D.h"

//\n become \0
static void	replace_nl(char	*str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	str[i] = '\0';
}

char	*get_textures_path(char *line)
{
	int		i;
	char	*path;

	i = 0;
	while (line[i] != '.')
		i++;
	path = ft_strdup(line + i);
	replace_nl(path);
	return (path);
}

int	parse_line(t_data *data, char *line)
{
	if (!line || !*line || isempty(line) || map_begin(line))
		return (0);
	else if (line[0] == 'N' && line[1] && line[1] == 'O')
		data->no_text = get_textures_path(line);
	else if (line[0] == 'S' && line[1] && line[1] == 'O')
		data->so_text = get_textures_path(line);
	else if (line[0] == 'W' && line[1] && line[1] == 'E')
		data->we_text = get_textures_path(line);
	else if (line[0] == 'E' && line[1] && line[1] == 'A')
		data->ea_text = get_textures_path(line);
	else if (line[0] == 'F' && line[1] && line[1] == ' ')
		data->floor_colors = get_bg_colors(line);
	else if (line[0] == 'C' && line[1] && line[1] == ' ')
		data->ceiling_colors = get_bg_colors(line);
	else
		return (ft_printf(2, "Error.\nInvalid line in file.\n"), 1);
	return (0);
}

//Get the map in a file .cub and put it in a char**
char	**get_map(char *map_tosplit, int fd)
{
	char	*line;
	char	*tmp;
	char	**map;

	tmp = NULL;
	line = get_next_line(fd);
	while (line && *line != '\n')
	{
		tmp = ft_strjoin(map_tosplit, line);
		if (map_tosplit)
			free(map_tosplit);
		map_tosplit = ft_strdup(tmp);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	map = ft_split(map_tosplit, "\n");
	free(map_tosplit);
	free(line);
	get_next_line(-1);
	return (map);
}

char	**read_map(t_data *data, char *filename)
{
	int		fd;
	char	**map;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (perror("map file"), NULL);
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	if (parse_line(data, line))
		return (get_next_line(-1), free(line), fire_exit(data, NULL), NULL);
	while (line && !map_begin(line))
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			return (NULL);
		if (parse_line(data, line))
			return (get_next_line(-1), free(line), fire_exit(data, NULL), NULL);
	}
	map = get_map(line, fd);
	if (!check_error(data, map))
		return (fire_exit(data, map), NULL);
	return (close(fd), map);
}
