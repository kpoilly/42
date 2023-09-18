/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:32:27 by marvin            #+#    #+#             */
/*   Updated: 2023/09/10 13:32:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *mem, int oct, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)mem;
	i = 0;
	while (i < n)
	{
		*str = oct;
		str++;
		i++;
	}
	return (mem);
}
