/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 02:11:51 by jdoukhan          #+#    #+#             */
/*   Updated: 2023/11/13 10:50:09 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_match(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		k;
	int		len;
	char	*tab;

	i = 0;
	if (!s1)
		return (NULL);
	k = ft_strlen(s1) - 1;
	while (s1[i] && ft_match(s1[i], set))
		i++;
	while (k && ft_match(s1[k], set))
		k--;
	len = k - i + 1;
	if (len < 0)
		len = 0;
	tab = ft_calloc(len + 1, sizeof(char));
	if (!tab)
		return (NULL);
	s1 += i;
	ft_strlcpy(tab, s1, (k - i + 2));
	return (tab);
}
