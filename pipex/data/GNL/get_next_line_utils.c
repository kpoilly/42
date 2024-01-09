/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:35:54 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/09 11:49:54 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(char *src, int n)
{
	char	*dest;
	int		i;

	if (n < 0)
		n = ft_strlen(src);
	dest = malloc((n + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	isnewline(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	if (str[i] == '\n')
		return (i);
	return (-1);
}
