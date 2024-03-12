/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_skip_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:37:35 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/03/05 08:55:34 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_newline_append(char *dest, char *read)
{
	char	*tmp;

	tmp = ft_strjoin(dest, "\n");
	if (dest)
		free(dest);
	if (!tmp && read)
		return (free (read), NULL);
	dest = tmp;
	tmp = ft_strjoin(dest, read);
	if (!tmp && read && dest)
		return (free (read), free(dest), NULL);
	if (dest)
		free(dest);
	if (read)
		free(read);
	dest = tmp;
	return (dest);
}

char	*get_missing(char c)
{
	char	*dest;
	char	*read;

	dest = NULL;
	while (1)
	{
		if (c == '"')
			read = readline("dquote> ");
		else
			read = readline("quote> ");
		dest = ft_newline_append(dest, read);
		if (!dest)
			return (NULL);
		if (ft_strchr(dest, c))
			break ;
	}
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
