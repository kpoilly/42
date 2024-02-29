/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:26:37 by jdoukhan          #+#    #+#             */
/*   Updated: 2023/11/12 13:30:29 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*s2;
	char	*d2;

	if (dest == src)
		return (dest);
	s2 = (char *) src;
	d2 = (char *) dest;
	i = (int) n;
	i--;
	while (i >= 0)
	{
		d2[i] = s2[i];
		i--;
	}
	return (dest);
}
