/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:02:19 by lleciak           #+#    #+#             */
/*   Updated: 2024/03/25 09:35:20 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchara(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr(char *str, int fd)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	if (!str)
	{
		print_null(fd);
		return (6);
	}
	while (str[i])
	{
		write (fd, &str[i++], 1);
		len++;
	}
	return (len);
}

int	print_null(int fd)
{
	write(fd, "(null)", 6);
	return (6);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}
