/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:27:18 by marvin            #+#    #+#             */
/*   Updated: 2023/09/12 18:27:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;
	int		lenstr;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && in_set(s1[i], set))
		i++;
	while (j && in_set(s1[j], set))
		j--;
	lenstr = j - i + 1;
	if (lenstr < 0)
		lenstr = 0;
	str = malloc((lenstr + 1) * sizeof(char));
	if (!str)
		return (NULL);
	s1 += i;
	ft_strlcpy(str, s1, ((j - i + 1) + 1));
	return (str);
}
