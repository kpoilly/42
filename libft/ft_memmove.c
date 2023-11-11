/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:02:48 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/10 20:33:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str_src;
	unsigned char	*str_dst;

	if (dest == src)
		return (dest);
	str_src = (unsigned char *)src;
	str_dst = (unsigned char *)dest;
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
