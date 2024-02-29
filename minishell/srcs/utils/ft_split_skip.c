/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_skip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:37:35 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/18 13:56:50 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//c is splitter
static int	count_words(char **s, char c, char *skip)
{
	int		count;
	int		i;
	int		len;

	i = 0;
	count = 0;
	len = ft_strlen(*s) - 1;
	if (s && (*s)[i] && (*s)[i] != c)
		count++;
	while (s && *s && i <= len)
	{
		if (in_charset((*s)[i], skip))
		{
			i = skip_skipset(s, i);
			if (i < 0)
				return (-1);
		}
		else if (*s && i < len && (*s)[i] && (*s)[i] == c && (*s)[i + 1] != c)
			count++;
		i++;
		len = ft_strlen(*s) - 1;
	}
	return (count);
}

static char	*add_word(char *s, char c, int *add, char *skip)
{
	int		len;
	char	*str;
	char	d;
	int		max;

	len = 0;
	max = ft_strlen(s);
	while (s && *s && s[*add] && s[*add] == c)
		(*add)++;
	while (s && *s && *add < max && s[*add] && s[*add] != c)
	{
		if (in_charset(s[*add], skip))
		{
			d = s[(*add)++];
			len++;
			while (s[*add] && s[*add] != d && (*add)++)
				len++;
		}
		(*add)++;
		len++;
	}
	str = ft_strndup(s + *add - len, len);
	return (str);
}

//Split but skips the skipset
//c is splitter, skip are to skip
char	**ft_split_skip(char *s, char c, char *skip)
{
	int		count;
	char	**tab;
	int		i;
	int		add;
	int		j;

	if (!s)
		return (NULL);
	count = count_words(&s, c, skip);
	if (count < 0)
		return (NULL);
	tab = malloc((count + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (i < count)
	{
		add = 0;
		tab[i] = add_word(s + j, c, &add, skip);
		if (!tab[i++])
			return (ft_free_strtab(tab), NULL);
		j += add;
	}
	return (tab[i] = NULL, free(s), tab);
}
