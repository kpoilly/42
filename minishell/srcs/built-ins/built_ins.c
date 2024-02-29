/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:34:19 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/26 15:58:50 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Check if cmd is a builtin
//forked if exit(0) needed.
int	is_built_in(char *cmd, int forked)
{
	if ((!forked && \
	(check_word(cmd, "cd", 0) || check_word(cmd, "exit", 0) || \
	check_word(cmd, "export", 0) || check_word(cmd, "unset", 0))) || \
	(forked && \
	(check_word(cmd, "echo", 0) || check_word(cmd, "env", 0) || \
	check_word(cmd, "history", 0) || check_word(cmd, "help", 0) || \
	check_word(cmd, "pwd", 0) || check_word(cmd, "exit", 0))))
		return (1);
	return (0);
}

static int	stat_export(t_shell *sh, char **full_cmd)
{
	char	**cmd;
	int		exit_code;

	if (full_cmd[1])
	{
		if (full_cmd[1][0] == '=')
			return (bi_export(sh, full_cmd[1], NULL));
		cmd = ft_split(full_cmd[1], '=');
		if (!cmd)
			on_crash(sh);
		exit_code = bi_export(sh, cmd[0], cmd[1]);
		ft_free_strtab(cmd);
		return (exit_code);
	}
	return (bi_env(sh), 0);
}

//Call the built-in after having called is_builtin
//forked if exit(0) is needed.
int	built_ins(t_shell *sh, char **full_cmd)
{
	if (check_word(full_cmd[0], "exit", 1))
		return (bi_exit(sh, full_cmd));
	else if (check_word(full_cmd[0], "pwd", 1))
		return (bi_pwd(sh));
	else if (check_word(full_cmd[0], "env", 1))
		return (bi_env(sh));
	else if (check_word(full_cmd[0], "cd", 1))
		return (bi_cd(sh, full_cmd));
	else if (check_word(full_cmd[0], "echo", 1))
		return (bi_echo(sh, full_cmd));
	else if (check_word(full_cmd[0], "export", 1))
		return (stat_export(sh, full_cmd));
	else if (full_cmd[1] && check_word(full_cmd[0], "unset", 1))
		return (bi_unset(sh, full_cmd[1]));
	else if (check_word(full_cmd[0], "history", 1))
		return (bi_history(sh));
	else if (check_word(full_cmd[0], "help", 1))
		return (bi_help(sh));
	return (0);
}
