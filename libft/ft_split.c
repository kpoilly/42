/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:17:02 by marvin            #+#    #+#             */
/*   Updated: 2023/09/12 11:17:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	if (*s != c && *s != ' ')
	{
		count++;
		s++;
	}
	while (*s)
	{
		if (*s == c && *(s + 1) != c)
			count++;
		s++;
	}
	return (count);
}

char	*add_word(const char *s, char c, int *add)
{
	int		len;
	char	*str;

	len = 0;
	while (s[*add] && s[*add] == c)
		(*add)++;
	while (s[*add] && s[*add] != c)
	{
		(*add)++;
		len++;
	}
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	(*add) -= len;
	len = 0;
	while (s[*add] && s[*add] != c)
		str[len++] = s[(*add)++];
	str[len] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**tab;
	int		i;
	int		add;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	tab = malloc((count + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < count)
	{
		add = 0;
		tab[i++] = add_word(s, c, &add);
		s += add;
	}
	tab[count] = NULL;
	return (tab);
}
