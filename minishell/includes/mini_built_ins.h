/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_built_ins.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:03:26 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/03/13 12:35:06 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_BUILT_INS_H
# define MINI_BUILT_INS_H

# include "structs.h"

//built-in functions

int		built_ins(t_shell *sh, char **full_cmd);
int		is_built_in(char *cmd, int forked);

int		bi_cd(t_shell *sh, char **cmd);
int		bi_echo(t_shell *sh, char **cmd);
int		bi_env(t_shell *sh);
int		bi_exit(t_shell *sh, char **full_cmd);
int		bi_force_export(t_shell *sh, char *var, char *value);
int		bi_export(t_shell *sh, char *var, char *value);
int		bi_pwd(t_shell *sh);
int		bi_unset(t_shell *sh, char **vars);

//bonus built-ins
int		bi_history(t_shell *sh);
void	bi_add_history(t_shell *sh, char *prompt);
int		bi_help(t_shell *sh);

# define HELP_MESSAGE "\n	Minishell, version 2.98.1\n\
	Code worked on by kpoilly and jdoukhan.\n\n\
	Use 'help' to show this help message.\n\n\
	cd [- | dir] : change active directory.\n\
	\t  -  : brings you back to $OLDPWD.\n\
	\t  [] : no arg brings you back to $HOME, root if not defined.\n\
	\t  .. : change to parent dir, root if already at root.\n\
	\n\
	echo [-n] [strings ...] : print strings.\n\
	\t\t     -n : no trailing newline.\n\n\
	env : print all envp.\n\n\
	exit [exit_code] : exit the shell with exit_code, 0 if none given.\n\
	\n\
	export VAR=VALUE : Set an env VAR to VALUE.\n\
	\t\t   Creates one if none found in envp, else edit it.\n\n\
	history : show command history.\n\n\
	pwd : print current directory.\n\n\
	unset {var} : remove env var from envp.\n\n"

#endif
