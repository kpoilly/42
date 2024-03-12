/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:09:44 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/03/07 15:12:47 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//To free
static char	**get_path(char **envp)
{
	int	i;

	i = 0;
	while (envp && envp[i])
	{
		if (envp[i][0] && envp[i][1] && envp[i][2]
			&& envp[i][3] && envp[i][4]
			&& envp[i][0] == 'P' && envp[i][1] == 'A'
			&& envp[i][2] == 'T' && envp[i][3] == 'H' && envp[i][4] == '=')
			return (ft_split(&envp[i][5], ':'));
		i++;
	}
	return (NULL);
}

static void	ft_free_absolute(char **path, char *cmd)
{
	if (cmd)
		free(cmd);
	ft_free(path);
}

static void	ft_str_exist_but_empty(char **str)
{
	int	i;

	if (str[0] && !str[0][0])
	{
		i = 0;
		free(str[0]);
		while (str[++i])
			str[i - 1] = str[i];
		str[i - 1] = NULL;
		i = 0;
		if (!str[0])
			str[0] = ft_strdup("echo");
	}
}

char	*absolute_path(t_shell *sh, char **str, char **envp)
{
	int		i;
	char	*absolute_path;
	char	*cmd;
	char	**path;

	(ft_str_exist_but_empty(str), i = 0);
	if ((str[0] &&!str[0][0]) || (is_built_in(str[0], -1) || \
	(ft_strchr(str[0], '/') && !access(str[0], F_OK & X_OK))))
		return (ft_strdup(str[0]));
	path = get_path(envp);
	if (!path)
		return (ft_putstr_fd("path not found\n", 2), NULL);
	cmd = ft_strjoin("/", str[0]);
	while (cmd && path && path[i])
	{
		absolute_path = ft_strjoin(path[i++], cmd);
		if (!absolute_path)
			break ;
		if (absolute_path && !access(absolute_path, F_OK & X_OK))
			return (ft_free_absolute(path, cmd), absolute_path);
		free(absolute_path);
	}
	return (ft_perror(sh, str[0], NULL, ": command not found"), \
	ft_free_absolute(path, cmd), NULL);
}
