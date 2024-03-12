/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:22:47 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/03/06 15:04:31 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Frees the correspounding string to put the new value inside envp.
static void	ft_edit_env(t_shell *sh, char *var, char *value)
{
	int		i;
	size_t	new_len;

	new_len = ft_strlen(var) + ft_strlen(value) + 2;
	i = get_env_index(sh, var);
	if (i < 0)
		on_crash(sh);
	if (ft_strlen(sh->envp[i]) < new_len)
	{
		free(sh->envp[i]);
		sh->envp[i] = NULL;
		sh->envp[i] = ft_calloc(new_len, sizeof (char));
		if (!sh->envp[i])
			on_crash(sh);
	}
	sh->envp[i][0] = 0;
	ft_strlcat(sh->envp[i], var, new_len);
	ft_strlcat(sh->envp[i], "=", new_len);
	if (value)
		ft_strlcat(sh->envp[i], value, new_len);
}

//Frees envp while copying it + 1 and initializes its value.
static void	ft_create_env(t_shell *sh, char *var, char *value)
{
	size_t	i;
	size_t	lenvp;
	char	**envp;

	i = 0;
	envp = sh->envp;
	lenvp = ft_strtablen(envp);
	sh->envp = ft_calloc((lenvp + 2), sizeof (char *));
	if (!sh->envp)
		on_crash(sh);
	while (i < lenvp)
	{
		sh->envp[i] = ft_strdup(envp[i]);
		if (!sh->envp[i++])
			on_crash(sh);
	}
	sh->envp[i] = malloc(ft_strlen(var) + ft_strlen(value) + 2 * sizeof (char));
	if (!sh->envp[i])
		(ft_free_strtab(envp), on_crash(sh));
	(ft_free_strtab(envp), sh->envp[i][0] = 0);
	ft_strlcat(sh->envp[i], var, ft_strlen(var) + ft_strlen(value) + 2);
	if (value)
		ft_strlcat(sh->envp[i], "=", ft_strlen(var) + ft_strlen(value) + 2);
	if (value)
		ft_strlcat(sh->envp[i], value, ft_strlen(var) + ft_strlen(value) + 2);
}

//BUILT-IN
//Adds or edit a var from envp.
int	bi_export(t_shell *sh, char *var, char *value)
{
	if (var && value && get_var(sh, var))
		ft_edit_env(sh, var, value);
	else if (var && !value && get_var(sh, var))
		return (0);
	else if (var && var[0] && !get_var(sh, var) && \
	(ft_isalpha(var[0]) || var[0] == '_'))
		ft_create_env(sh, var, value);
	else
	{
		ft_perror(sh, "export : `", var, "': not a valid identifier");
		return (1);
	}
	return (0);
}

//Bi export no unvalid identifier
int	bi_force_export(t_shell *sh, char *var, char *value)
{
	if (get_var(sh, var))
		ft_edit_env(sh, var, value);
	else
		ft_create_env(sh, var, value);
	return (0);
}
