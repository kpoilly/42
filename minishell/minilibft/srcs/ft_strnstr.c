/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:56:03 by jdoukhan          #+#    #+#             */
/*   Updated: 2023/11/12 12:12:17 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (!little[0])
		return ((char *)big);
	while (len > 0 && *big)
	{
		if (*big == little[0] && !ft_strncmp(big, little, ft_strlen(little))
			&& ft_strlen(little) <= len)
			return ((char *) big);
		big++;
		len--;
	}
	return (NULL);
}
