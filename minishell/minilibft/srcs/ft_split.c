/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:37:35 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/02 15:26:36 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab && tab[i])
		free(tab[i++]);
	if (tab)
		free(tab);
	return (NULL);
}

static size_t	ft_countwords(char const *str, char const delim)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == delim)
			i++;
		if (str[i] != delim && str[i])
			words++;
		while (str[i] != delim && str[i])
			i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	tab = ft_calloc((ft_countwords(s, c) + 1), sizeof(char *));
	if (!tab)
		return (NULL);
	while (k < ft_countwords(s, c))
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		tab[k] = ft_substr(s, j, i - j);
		if (!tab[k++])
			return (ft_free(tab));
	}
	tab[k] = NULL;
	return (tab);
}
