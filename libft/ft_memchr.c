/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:43:09 by marvin            #+#    #+#             */
/*   Updated: 2023/09/13 11:43:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *mem, int c, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)mem;
	i = 0;
	while (str[i] && i < n)
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (NULL);
}
