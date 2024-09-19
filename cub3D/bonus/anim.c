/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:02:12 by lleciak           #+#    #+#             */
/*   Updated: 2024/09/17 19:12:17 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/cub3D.h"

char	*get_path(char *path, int i)
{
	char	*ret;
	char	*nb;
	char	*tmp;

	ret = ft_strndup(path, (ft_strlen(path) - 4));
	nb = ft_itoa(i);
	tmp = ft_strjoin(ret, nb);
	free(ret);
	ret = ft_strjoin(tmp, ".xpm");
	free(tmp);
	free(nb);
	return (ret);
}

void	path_anim(t_data *data, t_anim *list, char *path, int loop)
{
	char	*cut_path;
	t_img	*current;

	list->size = 0;
	current = list->lst;
	while (current->img)
	{
		cut_path = get_path(path, list->size + 2);
		list->size++;
		current->next = malloc(sizeof(t_img));
		load_texture(data, current->next, cut_path);
		current->next->prev = current;
		current = current->next;
		free(cut_path);
	}
	current = current->prev;
	free(current->next);
	if (loop)
		current->next = list->lst;
	if (loop)
		list->lst->prev = current;
	if (!loop)
		current->next = NULL;
	if (!loop)
		list->lst->prev = NULL;
}

void	setup_img_anim(t_data *data)
{
	if (data->anim_no.lst->img)
		path_anim(data, &data->anim_no, data->no_text, 1);
	if (data->anim_we.lst->img)
		path_anim(data, &data->anim_we, data->we_text, 1);
	if (data->anim_so.lst->img)
		path_anim(data, &data->anim_so, data->so_text, 1);
	if (data->anim_ea.lst->img)
		path_anim(data, &data->anim_ea, data->ea_text, 1);
	if (data->door_tex.lst->img)
		path_anim(data, &data->door_tex, "./utils/textures/door.xpm", 0);
	data->anim_no.timer = clock();
	data->anim_we.timer = clock();
	data->anim_so.timer = clock();
	data->anim_ea.timer = clock();
	data->door_tex.timer = clock();
}
