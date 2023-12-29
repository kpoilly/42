/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:52:34 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/29 14:14:28 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	nb = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = (nb * 10) + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	if (*s && *s != c)
	{
		count++;
		s++;
	}
	while (*s && *(s + 1))
	{
		if (*s == c && *(s + 1) != c)
			count++;
		s++;
	}
	return (count);
}

static char	*add_word(const char *s, char c, int *add)
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
		tab[i] = add_word(s, c, &add);
		if (!tab[i])
			return (ft_free(tab), NULL);
		i++;
		s += add;
	}
	tab[count] = NULL;
	return (tab);
}
