/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:34:46 by idoukhan          #+#    #+#             */
/*   Updated: 2024/02/13 13:41:12 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//No Mallocs
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	sized;
	size_t	sizes;

	sizes = ft_strlen(src);
	if (!size)
		return (sizes);
	sized = ft_strlen(dst);
	j = 0;
	if (sized > size)
		return (size + sizes);
	while (src[j] && size - 1 > sized + j)
	{
		dst[sized + j] = src[j];
		j++;
	}
	dst[sized + j] = '\0';
	return (sized + sizes);
}
