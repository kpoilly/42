/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:02:48 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/10 17:52:04 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str_src;
	unsigned char	*str_dst;
	size_t			i;

	if (dest == src)
		return (dest);
	str_src = (unsigned char *)src;
	str_dst = (unsigned char *)dest;
	i = 0;
	if (str_dst > str_src)
	{
		while (n > 0)
		{
			str_dst[n - 1] = str_src[n - 1];
			n--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
