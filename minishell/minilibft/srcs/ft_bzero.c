/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:23:15 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/01 16:56:29 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Classic bzero
void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*zero;

	i = 0;
	zero = (char *) s;
	while (i < n)
		zero[i++] = 0;
}
