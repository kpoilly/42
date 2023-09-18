/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:45:27 by marvin            #+#    #+#             */
/*   Updated: 2023/09/10 10:45:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, char c)
{
	char	*dest;

	dest = (char *)str;
	dest = ft_strchr(dest, c);
	if (!dest)
		return (NULL);
	while (*dest && ft_strchr(dest + 1, c))
		dest = ft_strchr(dest + 1, c);
	return (dest);
}
