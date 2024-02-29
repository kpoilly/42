/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtab_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:14:24 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/13 12:43:41 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_tabtab(char ***tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab && tab[i])
	{
		ft_free_strtab(tab[i]);
		tab[i] = NULL;
		i++;
	}
	if (tab)
		free(tab);
	tab = NULL;
}

void	ft_free_strtab(char **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return ;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
}

size_t	ft_strtablen(char **s)
{
	size_t	i;

	i = 0;
	while (s && *s && s[i] != NULL)
		i++;
	return (i);
}

size_t	ft_tabtablen(char ***s)
{
	size_t	i;

	i = 0;
	while (s && *s && **s && s[i] && s[i] != NULL)
		i++;
	return (i);
}
