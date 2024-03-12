/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:23:03 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/29 19:08:47 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*remove_last_dir(t_shell *sh, char *abs_path)
{
	int		i;
	char	*tmp;

	i = ft_strlen(abs_path) - 1;
	while (i > 0 && abs_path[i] && abs_path[i] != '/')
		i--;
	if (i <= 0)
		tmp = ft_strdup("/");
	else
		tmp = ft_strnjoin(NULL, abs_path, i);
	free(abs_path);
	if (!tmp)
		on_crash(sh);
	return (tmp);
}

static char	*check_op(t_shell *sh, char *abs_path, char **cmd_tab, int i)
{
	char	*tmp;
	int		len;

	if (!ft_strncmp(cmd_tab[i], "..", 2))
		abs_path = remove_last_dir(sh, abs_path);
	if (ft_isalnum(cmd_tab[i][0]))
	{
		tmp = ft_strjoin(abs_path, "/");
		free(abs_path);
		if (!tmp)
			on_crash(sh);
		len = 0;
		while (cmd_tab[i][len] && cmd_tab[i][len] != '/')
			len++;
		abs_path = ft_strnjoin(tmp, cmd_tab[i], len);
		free(tmp);
		if (!abs_path)
			on_crash(sh);
	}
	return (abs_path);
}

//malloc
static char	*set_abs_path(t_shell *sh, char	**cmd)
{
	char	*abs_path;

	if (!ft_strncmp(cmd[1], ".", 1) || !ft_strncmp(cmd[1], "./", 2)
		|| ft_isalnum(cmd[1][0]))
	{
		abs_path = ft_strdup(get_var(sh, "PWD"));
		if (!abs_path)
			on_crash(sh);
		return (abs_path);
	}
	return (NULL);
}

char	*ft_cd_no_arg(t_shell *sh);

//faudra proteger les 2 dup des return du haut (ntm la norm)
static char	*get_abs_path(t_shell *sh, char **cmd)
{
	char	**cmd_tab;
	char	*abs_path;
	int		i;

	if (!cmd[1])
		return (ft_cd_no_arg(sh));
	if (!ft_strncmp(cmd[1], "-", 1))
		return (ft_strdup(get_var(sh, "OLDPWD")));
	ft_tilde(sh, cmd);
	abs_path = set_abs_path(sh, cmd);
	if (cmd[1])
	{
		cmd_tab = ft_split(cmd[1], '/');
		if (!cmd_tab)
			(free(abs_path), on_crash(sh));
		i = 0;
		while (cmd_tab[i])
		{
			if (abs_path && access(abs_path, F_OK) < 0)
				return (ft_free_strtab(cmd_tab), abs_path);
			abs_path = check_op(sh, abs_path, cmd_tab, i++);
		}
		ft_free_strtab(cmd_tab);
	}
	return (abs_path);
}

//BUILT-IN
//Change current directory.
int	bi_cd(t_shell *sh, char **cmd)
{
	char	*abs_path;
	int		check_chdir;

	if (ft_strtablen(cmd) > 2)
		return (ft_putstr_fd("cd: too many arguments\n", 2), 1);
	abs_path = get_abs_path(sh, cmd);
	if (!abs_path)
		return (1);
	if (access(abs_path, F_OK) < 0)
		return (ft_perror(sh, "cd: ", cmd[1], " no such file or directory"), \
		free(abs_path), 1);
	check_chdir = chdir(abs_path);
	if (!check_chdir)
	{
		bi_export(sh, "OLDPWD", get_var(sh, "PWD"));
		bi_export(sh, "PWD", abs_path);
		return (free(abs_path), refresh_prompt(sh), 0);
	}
	else
	{
		ft_perror(sh, "cd: ", NULL, NULL);
		perror(cmd[1]);
	}
	return (free(abs_path), 1);
}
