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
	str = ft_strchr(str, c);
	if (!str)
		return (NULL);
	while (*str && ft_strchr(str + 1, c))
		str = ft_strchr(str + 1, c);
	return (str);
}
