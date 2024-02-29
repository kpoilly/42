/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:19:15 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/29 15:51:06 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft_int.h"

static char	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;
	size_t	i;
	size_t	mult_size;

	i = 0;
	mult_size = nmemb * size;
	if (size && mult_size / size != nmemb)
		return (NULL);
	tab = malloc(mult_size);
	if (!tab)
		return (NULL);
	i = 0;
	tab[i] = 0;
	return (tab);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*tab;

	i = 0;
	j = 0;
	tab = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	while (tab && s1 && s1[i])
		tab[j++] = s1[i++];
	i = 0;
	while (tab && s2[i])
		tab[j++] = s2[i++];
	if (tab && s1)
		free(s1);
	if (!tab)
		return (NULL);
	tab[j] = 0;
	return (tab);
}

static int	ft_return(char *line, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line && line[i])
		if (line[i++] == '\n')
			break ;
	while (line && line[i])
	{
		buffer[j++] = line[i];
		line[i] = 0;
		i++;
	}
	while (j < BUFFER_SIZE + 1)
		buffer[j++] = 0;
	return (1);
}

static int	ft_match(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

int	ft_while(t_list *file, char **line)
{
	size_t	k;
	ssize_t	a;

	while (!ft_match(file->str))
	{
		k = 0;
		while (k <= BUFFER_SIZE)
			(file->str)[k++] = 0;
		a = read(file->fd, file->str, BUFFER_SIZE);
		if (a < 0)
		{
			(file->str)[0] = 0;
			if (*line)
				free(*line);
			return (1);
		}
		if (a == 0)
		{
			file->to_free = true;
			return (0);
		}
		*line = ft_strjoin_gnl(*line, file->str);
	}
	ft_return(*line, file->str);
	return (0);
}
