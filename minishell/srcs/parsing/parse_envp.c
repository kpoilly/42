/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:05:47 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/03/06 15:04:12 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Looks for a word at the beginning of a string
//Returns the content of the env var if found, NULL if not
static char	*get_word(char *s, const char *word)
{
	size_t	i;

	i = 0;
	if (!s || !word)
		return (NULL);
	while (word[i] && s[i] && word[i] == s[i])
		i++;
	if ((!s[i] && i != ft_strlen(word) && ft_strncmp(s, word, i + 1)) \
	|| (s[i] && s[i] != '='))
		return (NULL);
	return (&s[i + 1]);
}

//Returns content of var passed, NULL if not found
char	*get_var(t_shell *sh, char *var)
{
	size_t	i;

	i = 0;
	while (sh->envp[i] && !get_word(sh->envp[i], var))
		i++;
	if (sh->envp[i])
		return (get_word(sh->envp[i], var));
	return (NULL);
}

//Returns the index in envp of var passed
// -1 if not found
int	get_env_index(t_shell *sh, char *var)
{
	int	i;

	i = 0;
	while (sh->envp[i] && !get_word(sh->envp[i], var))
		i++;
	if (sh->envp[i])
		return (i);
	return (-1);
}
