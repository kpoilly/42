/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:07:53 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/31 10:33:35 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Put nl=0 to check if the strings are the exact copy
//Else a newline of difference is accepted.
//> 1 if found, else 0
int	check_word(char *s, const char *word, int nl)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (word[i] && s[i] && word[i] == s[i])
		i++;
	if (i != ft_strlen(word) || (!nl && s[i])
		|| (nl && s[i] && s[i] != '\n'))
		return (0);
	return (1);
}
