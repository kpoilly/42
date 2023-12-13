/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:29:20 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/13 14:15:16 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstrlen(char *str)
{
	if (!str)
	{
		ft_putstrlen("(null)");
		return (6);
	}
	ft_putstr(str);
	return (ft_strlen(str));
}