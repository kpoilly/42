/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:28:05 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/01 16:56:45 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Classic calloc
void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;
	size_t	mult_size;

	mult_size = nmemb * size;
	if (size && mult_size / size != nmemb)
		return (NULL);
	tab = malloc (mult_size);
	if (!tab)
		return (NULL);
	ft_bzero((void *) tab, mult_size);
	return ((void *) tab);
}
