/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:29:20 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/16 11:38:36 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(int fd, char *s)
{
	while (*s)
		write(fd, s++, 1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstrlen(int fd, char *str)
{
	if (!str)
	{
		ft_putstrlen(fd, "(null)");
		return (6);
	}
	ft_putstr(fd, str);
	return (ft_strlen(str));
}
