/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:59:32 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/28 12:03:49 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**ft_only_right(t_shell *sh, int i, int *j, int *k)
{
	char	**tmp;

	tmp = malloc ((ft_strtablen(sh->input[i]) + 3) * sizeof (char *));
	if (!tmp)
		on_crash(sh);
	sh->bi_ret = 0;
	while (sh->bi_ret < (int) ft_strtablen(sh->input[i]))
	{
		tmp[sh->bi_ret] = sh->input[i][sh->bi_ret];
		(sh->bi_ret)++;
	}
	sh->bi_ret = (*j);
	if (sh->input[i][*j][*k] == sh->input[i][*j][*k + 1])
		(*k)++;
	tmp[*j + 1] = ft_strdup(&sh->input[i][*j][*k + 1]);
	tmp[*j][(*k + 1)] = 0;
	return (tmp);
}

static char	**ft_both_sides(t_shell *sh, int i, int *j, int *k)
{
	char	**tmp;

	tmp = malloc ((ft_strtablen(sh->input[i]) + 3) * sizeof (char *));
	if (!tmp)
		on_crash(sh);
	while (++(sh->bi_ret) < (int) ft_strtablen(sh->input[i]))
		tmp[(sh->bi_ret)] = sh->input[i][sh->bi_ret];
	sh->bi_ret = *k;
	tmp[*j + 1] = ft_strdup(&sh->input[i][*j][*k]);
	if (!tmp[*j + 1])
		(free(tmp), on_crash(sh));
	if (sh->input[i][*j][*k] == sh->input[i][*j][*k + 1])
		(*k)++;
	if (sh->input[i][*j][*k + 1])
		tmp[*j + 2] = ft_strdup(&sh->input[i][*j][*k + 1]);
	if (sh->input[i][*j][*k + 1])
	{
		tmp[*j][sh->bi_ret] = 0;
		sh->bi_ret = *j;
		tmp[*j + 1][*k + 1 - ft_strlen(tmp[*j])] = 0;
		return ((*j)++, tmp);
	}
	tmp[*j][sh->bi_ret] = 0;
	tmp[*j + 1][*k + 1 - ft_strlen(tmp[*j])] = 0;
	return (sh->bi_ret = *j, tmp);
}

void	ft_resplit(t_shell *sh, int i, int *j, int *k)
{
	char	**tmp;

	sh->bi_ret = -1;
	if (*k == 0)
		tmp = ft_only_right(sh, i, j, k);
	else
		tmp = ft_both_sides(sh, i, j, k);
	(*j) += 2;
	while (sh->input[i][++(sh->bi_ret)])
		tmp[(*j)++] = sh->input[i][sh->bi_ret];
	free(sh->input[i]);
	sh->input[i] = tmp;
	sh->input[i][*j] = NULL;
	(*j)--;
	*k = -1;
	sh->bi_ret = 0;
}

static void	ft_while_k(t_shell *sh, int i, int *j, int *k)
{
	char	c;

	(*k) = 0;
	while (sh->input[i] && sh->input[i][*j] && sh->input[i][*j][(*k)])
	{
		if (sh->input[i][*j][(*k)] == '"' || sh->input[i][*j][(*k)] == '\'')
		{
			c = sh->input[i][*j][(*k)++];
			while (sh->input[i][*j][(*k)] && sh->input[i][*j][(*k)] != c)
				(*k)++;
		}
		else if ((sh->input[i][*j][(*k)] == '<' || \
		sh->input[i][*j][(*k)] == '>') && \
		(((*k) != 0 && sh->input[i][*j][(*k) - 1] != '>' && \
		sh->input[i][*j][(*k) - 1] != '<') || (sh->input[i][*j][(*k) + 1] && \
		((sh->input[i][*j][(*k) + 1] != '<' && \
		sh->input[i][*j][(*k) + 1] != '>') || sh->input[i][*j][(*k) + 2]))))
			ft_resplit(sh, i, j, k);
		(*k)++;
	}
}

void	split_redirects(t_shell *sh)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (sh->input[i])
	{
		j = 0;
		while (sh->input[i] && sh->input[i][j])
		{
			ft_while_k(sh, i, &j, &k);
			j++;
		}
		i++;
	}
}
