/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:10:54 by kpoilly           #+#    #+#             */
/*   Updated: 2024/09/17 14:26:46 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (1);
		else
			i++;
	}
	if (s[i] == c)
		return (1);
	return (0);
}

char	*read_line(char *stock, int fd, int *r)
{
	char	*buffer;
	char	*temp;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stock, '\n') && *r)
	{
		*r = read(fd, buffer, BUFFER_SIZE);
		buffer[*r] = '\0';
		if (*r == -1)
			return (free(buffer), free(stock), NULL);
		temp = ft_strjoin(stock, buffer);
		free(stock);
		stock = ft_strdup(temp);
		free(temp);
	}
	free(buffer);
	return (stock);
}

char	*ft_free(char **stock)
{
	if (!**stock)
	{
		free(*stock);
		*stock = NULL;
		return (NULL);
	}
	return (*stock);
}

char	*get_next_line(int fd)
{
	static char	*stock = NULL;
	char		*line;
	int			len;
	int			r;

	r = 1;
	if (fd <= 0 || read(fd, NULL, 0) == -1)
		return (free(stock), NULL);
	stock = read_line(stock, fd, &r);
	if (!stock || !ft_free(&stock))
		return (NULL);
	len = ft_len(stock) + 1;
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, stock, len + 1);
	if (!*line)
		return (free(stock), free(line), NULL);
	ft_strlcpy(stock, stock + len, ft_strlen(stock) - len + 1);
	if (!r)
	{
		free(stock);
		stock = NULL;
	}
	return (line);
}
