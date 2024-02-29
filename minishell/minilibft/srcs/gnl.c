/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:15:41 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/29 15:50:53 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft_int.h"

static t_list	*ft_newstruct(int fd)
{
	t_list	*lst;
	int		i;

	i = 0;
	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	while (i < BUFFER_SIZE + 1)
		lst->str[i++] = 0;
	lst->fd = fd;
	lst->next = NULL;
	lst->to_free = false;
	return (lst);
}

static t_list	*ft_lstread(t_list *cursor, int fd)
{
	t_list	*file;

	file = cursor;
	while (file && file->next)
		file = file->next;
	if (file == cursor)
	{
		file->next = ft_newstruct(fd);
		if (!file->next)
			return (NULL);
		file = file->next;
	}
	file->fd = fd;
	return (file);
}

static char	*ft_free(t_list *start)
{
	t_list	*cursor;
	t_list	*prev;

	if (!start->next)
		return (NULL);
	while (start->next)
	{
		prev = start;
		cursor = start->next;
		while (cursor->next)
		{
			prev = cursor;
			cursor = cursor->next;
		}
		if (cursor && start->next)
			free(cursor);
		prev->next = NULL;
	}
	start->next = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_list	start = {.fd = -1, .next = NULL};
	t_list			*file;
	char			*line;
	t_list			*cursor;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free(&start));
	cursor = &start;
	file = ft_lstread(cursor, fd);
	if (!file)
		return (ft_free(&start));
	line = ft_strjoin_gnl(NULL, file->str);
	if (!line || ft_while(file, &line))
		return (NULL);
	if (line && !line[0])
		line = (free(line), NULL);
	if (file->to_free)
	{
		while (cursor->next && cursor->next != file)
			cursor = cursor->next;
		cursor->next = file->next;
		free(file);
	}
	return (line);
}
