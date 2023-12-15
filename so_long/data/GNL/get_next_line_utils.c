/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:06:56 by lleciak           #+#    #+#             */
/*   Updated: 2023/12/15 16:06:58 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;

	if (!s1)
		return (ft_strdup(s2));
	string = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!string)
		return (NULL);
	ft_strlcpy(string, (const char *)s1, ft_strlen(s1) + 1);
	ft_strlcat(string, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (string);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	size_dest;
	size_t	size_src;

	i = 0;
	size_src = ft_strlen(src);
	if (size == 0)
		return (size_src);
	size_dest = ft_strlen(dst);
	if (size_dest >= size)
		return (size_src + size);
	while (src[i] != '\0' && size_dest + i < size - 1)
	{
		dst[size_dest + i] = src[i];
		i++;
	}
	dst[size_dest + i] = '\0';
	if (size_dest > size)
		return (size + size_src);
	else
		return (size_src + size_dest);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size <= 0)
		return (0);
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(((ft_strlen(s) + 1) * sizeof(char)));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
