/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:03:58 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/03/08 13:13:11 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_terminate_env(t_shell *sh, char *str, int n)
{
	int		i;
	char	*var;

	i = 0;
	var = ft_strdup(str);
	if (!var)
		on_crash(sh);
	if ((ft_isdigit(*var)) || (*var == '-') || (*var == '$') || \
	(*var == '?') || (*var == '_' && (!(*(var + 1)) || *(var + 1) == ' ')))
	{
		i++;
		while (ft_isdigit(*var) && var[i] && (ft_isdigit(var[i])) && \
		(n == 0 || i < n - 1))
			i++;
	}
	else
		while (var && var[i] && (ft_isalnum(var[i]) || var[i] == '_') && \
		(n == 0 || i < n - 1))
			i++;
	var[i] = 0;
	return (var);
}

static int	ft_var_noexists(t_shell *sh, int *index, int *k, char *env)
{
	char	*temp;
	int		l;
	int		final_k;

	final_k = *k;
	temp = ft_calloc ((ft_strlen(sh->input[index[0]][index[1]]) + \
	ft_strlen(get_var(sh, env))), sizeof (char));
	l = 0;
	while (l < *k)
	{
		temp[l] = sh->input[index[0]][index[1]][l];
		l++;
	}
	*k += ft_strlen(env) + 1;
	while (sh->input[index[0]][index[1]][*k])
		temp[l++] = sh->input[index[0]][index[1]][(*k)++];
	temp[l] = 0;
	free(sh->input[index[0]][index[1]]);
	sh->input[index[0]][index[1]] = temp;
	*k = final_k;
	return (-ft_strlen(env) - 2);
}

static int	ft_var_exists(t_shell *sh, int *index, int *k, char *env)
{
	char	*temp;
	int		l;
	int		final_k;

	temp = ft_calloc ((ft_strlen(sh->input[index[0]][index[1]]) + \
	ft_strlen(get_var(sh, env))), sizeof (char));
	l = -1;
	while (++l < *k)
		temp[l] = sh->input[index[0]][index[1]][l];
	while (get_var(sh, env) && get_var(sh, env)[l - (*k) - 1])
	{
		temp[l] = get_var(sh, env)[l - (*k)];
		l++;
	}
	final_k = l;
	(*k) += ft_strlen(env) + 1;
	l--;
	while (sh->input[index[0]][index[1]][*k])
		temp[l++] = sh->input[index[0]][index[1]][(*k)++];
	temp[l] = 0;
	(*k) = final_k - 2;
	free(sh->input[index[0]][index[1]]);
	sh->input[index[0]][index[1]] = temp;
	return (ft_strlen(get_var(sh, env)) - ft_strlen(env) - 1);
}

int	ft_replace(t_shell *sh, int i, int *j, int *k)
{
	char	*env;
	int		index[2];
	int		len;

	index[0] = i;
	index[1] = *j;
	env = ft_terminate_env(sh, &sh->input[index[0]][index[1]][(*k) + 1], \
	sh->bi_ret);
	if (get_var(sh, env))
		len = ft_var_exists(sh, index, k, env);
	else
		len = ft_var_noexists(sh, index, k, env);
	if (env)
		free(env);
	sh->bi_ret = 0;
	return (len);
}

//Expands env inside sh->input if exists
void	expander(t_shell *sh)
{
	int		i;
	int		j;

	i = 0;
	while (sh->input[i])
	{
		j = 0;
		while (sh->input[i][j])
		{
			if (sh->input[i][j][0] && sh->input[i][j][1])
				ft_quotes_and_expand(sh, i, j);
			j++;
		}
		i++;
	}
}
