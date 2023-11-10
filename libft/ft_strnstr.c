/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:39:13 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/10 18:06:16 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	if (!ft_strlen(little))
		return ((char *)big);
	while (n > 0 && *big)
	{
		if (*big == little[0] && !ft_strncmp(big, little, ft_strlen(little))
			&& ft_strlen(little) <= n)
			return ((char *)big);
		big++;
		n--;
	}
	return (NULL);
}
