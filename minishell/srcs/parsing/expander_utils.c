/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:52:10 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/03/08 13:48:58 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_if_quotes(t_shell *sh, int i, int *j, int *k)
{
	int		n;
	char	c;

	n = 1;
	c = sh->input[i][*j][*k];
	while (sh->input[i][*j][*k + n] && sh->input[i][*j][*k + n] != c)
		n++;
	if (sh->input[i][*j][*k + n] && sh->input[i][*j][*k + n] == c)
	{
		if (ft_quotes_remover(&sh->input[i][*j][(*k)], k, n))
		{
			while ((*k) < n - 1)
			{
				if (ft_needs_expand(&sh->input[i][*j][*k]))
				{
					sh->bi_ret = n - 1;
					n += ft_replace(sh, i, j, k);
					(*k)--;
				}
				(*k)++;
			}
		}
	}
}

void	ft_quotes_and_expand(t_shell *sh, int i, int j)
{
	int		k;

	k = 0;
	while (sh->input[i][j][k])
	{
		if (sh->input[i][j][k] && (sh->input[i][j][k] == '"' || \
		sh->input[i][j][k] == '\''))
			ft_if_quotes(sh, i, &j, &k);
		else if (ft_needs_expand(&sh->input[i][j][k]))
			(ft_replace(sh, i, &j, &k));
		else
			k++;
	}
}

int	ft_quotes_remover(char *str, int *k, int n)
{
	int		i;
	int		ret_code;

	i = 0;
	ret_code = 0;
	if (str[0] && str[0] == '"')
		ret_code = 1;
	while (str[i] && str[i + 1] && i < n - 1)
	{
		str[i] = str[i + 1];
		i++;
	}
	if (!ret_code)
		(*k) += n - 1;
	while (str[i] && str[i + 1])
	{
		str[i] = str[i + 2];
		i++;
	}
	str[i] = 0;
	return (ret_code);
}

int	ft_needs_expand(char *str)
{
	if (!(str && *str && *(str + 1) && *str == '$' && \
		(ft_isalnum(*(str + 1)) || \
		((*(str + 1) == '$') || (*(str + 1) == '-') || \
		(*(str + 1) == '?') || (*(str + 1) == '_')))))
		return (0);
	else if (str && *str && *str != '$')
		return (0);
	return (1);
}
