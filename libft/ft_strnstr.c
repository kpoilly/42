/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 11:42:13 by marvin            #+#    #+#             */
/*   Updated: 2023/09/10 11:42:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *big, char *little, size_t n)
{
	if (!little)
		return (big);
	while (*big && n > 0)
	{
		if (*big == little[0] && !ft_strncmp(big, little, ft_strlen(little)))
			return (big);
		big++;
		n--;
	}
	return (NULL);
}
