/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:29:03 by jdoukhan          #+#    #+#             */
/*   Updated: 2023/11/12 13:34:36 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	*d2;

	if (dest == src)
		return (dest);
	d2 = (char *) dest;
	i = 0;
	if (&dest[0] < &src[0])
	{
		while (i < (int) n)
		{
			d2[i] = ((char *) src)[i];
			i++;
		}
	}
	else
	{
		i = (int) n;
		while (i > 0)
		{
			i--;
			d2[i] = ((char *)src)[i];
		}
	}
	return (dest);
}
