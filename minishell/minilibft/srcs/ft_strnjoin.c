/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 02:10:50 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/16 16:11:14 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//join n elem of s2 to s1
char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*tab;

	i = 0;
	j = 0;
	tab = ft_calloc(ft_strlen(s1) + n + 1, sizeof(char));
	if (!tab)
		return (NULL);
	while (s1 && s1[i])
		tab[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i] && i < n)
		tab[j++] = s2[i++];
	tab[j] = 0;
	return (tab);
}
