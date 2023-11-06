/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:02:48 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/06 12:09:01 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str_src;
	unsigned char	*str_dst;
	size_t			i;

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
	{
		while (i < n)
		{
			str_dst[i] = str_src[i];
			i++;
		}
	}
	return (dest);
}
