/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:27:51 by marvin            #+#    #+#             */
/*   Updated: 2023/09/13 11:27:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t size)
{
	void	**tab;
	int		i;

	if (!nelem || !size)
		return (NULL);
	tab = malloc(nelem * size);
	i = 0;
	while (i < nelem)
		ft_bzero(tab[i++], size);
	return (tab);
}
