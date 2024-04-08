/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:59:16 by lleciak           #+#    #+#             */
/*   Updated: 2024/03/27 12:42:25 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/headers/cub3D.h"

int	in_charset(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
		if (c == sep[i++])
			return (1);
	return (0);
}

char	*one_case(char *str, char *sep, int *add)
{
	int		i;
	int		len;
	char	*malloc_case;

	i = 0;
	len = 0;
	while (str[i] && in_charset(str[i], sep))
		i++;
	while (str[i] && !in_charset(str[i], sep))
	{
		len++;
		i++;
	}
	malloc_case = malloc((len + 1) * sizeof(char));
	i = i - len;
	*add = i + len;
	len = 0;
	while (str[i] && !in_charset(str[i], sep))
	{
		malloc_case[len] = str[i];
		len++;
		i++;
	}
	malloc_case[len] = '\0';
	return (malloc_case);
}

int	count_nb(char *str, char *sep)
{
	int	i;
	int	count;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (in_charset(str[i], sep))
			i++;
		else if (((!in_charset(str[i], sep) && in_charset(str[i + 1], sep))
				|| (!in_charset(str[i], sep) && str[i + 1] == '\0')))
		{
			count++;
			i++;
		}
		else
			i++;
	}
	return (count);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	**ft_split(char *str, char *sep)
{
	int		i;
	int		add;
	int		nb;
	char	**tab;

	nb = count_nb(str, sep);
	tab = malloc((nb + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < nb)
	{
		add = 0;
		tab[i] = one_case(str, sep, &add);
		if (!tab[i])
			return (free_tab(tab), NULL);
		str += add;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
