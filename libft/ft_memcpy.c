/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:49:22 by marvin            #+#    #+#             */
/*   Updated: 2023/09/10 13:49:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)dest;
	i = 0;
	while (i < n)
	{
		str[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}
