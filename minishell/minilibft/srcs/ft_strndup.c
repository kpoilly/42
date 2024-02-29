/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:28:49 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/02 15:25:53 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, int n)
{
	char	*tab;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (n < 0 || n > (int)ft_strlen(s))
		n = (int)ft_strlen(s);
	tab = ft_calloc((size_t)n + 1, (size_t) sizeof(char));
	if (!tab)
		return (NULL);
	while (s[i] && i < n)
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = 0;
	return (tab);
}
