/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:46:02 by lleciak           #+#    #+#             */
/*   Updated: 2024/04/11 18:27:40 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/headers/cub3D.h"

//add 2 chars at the end of a char*
char	*ft_strjoin_char(char *hex, char a, char b)
{
	int		len;
	int		i;
	char	*join;

	len = ft_strlen(hex);
	join = malloc((len + 3) * sizeof(char));
	if (!join)
		return (NULL);
	i = -1;
	while (hex[++i])
		join[i] = hex[i];
	join[len] = a;
	join[len + 1] = b;
	join[len + 2] = '\0';
	return (join);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	if (!n || !s1 || !s2)
		return (-1);
	i = 0;
	while ((s1[i] && s2[i] && s1[i] == s2[i]) && i < n - 1)
		i++;
	if ((!s1[i] && !s2[i]) || i == n - 1)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = (nb * 10) + (nptr[i] - '0');
		i++;
	}
	return (nb);
}

//convert an rgb int table into an hex int (for colors)
int	rgb_to_hex(int rgb[3])
{
	int		color;
	int		i;

	color = rgb[0];
	i = 1;
	while (i < 3)
		color = (color << 8) + rgb[i++];
	return (color);
}

int	isempty(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ((line[i] >= 9 && line[i] <= 13 && line[i] != '\n')
			|| line[i] == ' '))
		i++;
	return (line[i] == '\n');
}
