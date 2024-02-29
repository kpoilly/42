/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_skip_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:37:35 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/18 13:54:50 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_missing(char c)
{
	char	*dest;
	char	*tmp;
	char	*read;

	read = NULL;
	dest = ft_strdup("\n");
	while (!ft_strchr(dest, c))
	{
		if (c == '"')
			ft_printf("dquote> ");
		else
			ft_printf("quote> ");
		read = get_next_line(0);
		tmp = ft_strjoin(dest, read);
		if (!tmp && read && dest)
			return (free (read), free(dest), get_next_line(-1), NULL);
		if (dest)
			free(dest);
		if (read)
			free(read);
		dest = tmp;
	}
	get_next_line(-1);
	dest[ft_strlen(dest) - 1] = 0;
	return (dest);
}

//malloc
char	*clean_add(char	*s, char c)
{
	char	*dest;
	char	*input;

	input = get_missing(c);
	dest = ft_strjoin(s, input);
	if (input)
		free(input);
	return (dest);
}

int	in_charset(char c, char	*set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

//malloc
int	skip_skipset(char **s, int i)
{
	char	d;
	char	*tmp;

	d = (*s)[i++];
	while ((*s)[i] && (*s)[i] != d)
		i++;
	if (!(*s)[i])
	{
		tmp = clean_add(*s, d);
		if (!tmp)
			return (-1);
		free(*s);
		*s = tmp;
		while ((*s)[i] && (*s)[i] != d)
			i++;
	}
	if ((*s)[ft_strlen(*s) - 1] && (*s)[ft_strlen(*s) - 1] == '\n')
		(*s)[ft_strlen(*s) - 1] = 0;
	return (i);
}
