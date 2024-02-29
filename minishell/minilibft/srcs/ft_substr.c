/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 02:09:53 by jdoukhan          #+#    #+#             */
/*   Updated: 2023/11/13 10:40:08 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	else if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	tab = ft_calloc(len + 1, sizeof (char));
	if (!tab)
		return (NULL);
	while (s[i + start] && i < len)
	{
		tab[i] = s[i + start];
		i++;
	}
	tab[i] = 0;
	return (tab);
}
