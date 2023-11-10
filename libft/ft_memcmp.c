/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:18:41 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/10 18:13:24 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while ((((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
			&& i < n - 1)
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
