/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:39:53 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/03/04 15:17:40 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Get current dir without using envp.
//Return is allocated with malloc.
char	*get_current_dir(t_shell *sh)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		on_crash(sh);
	return (cwd);
}

//Fixes missing essential env var(s).
//SET HOME properly if not found plz.
void	set_minimal_env(t_shell *sh)
{
	char	*cwd;

	if (!get_var(sh, "_"))
		bi_export(sh, "_", "]");
	bi_force_export(sh, "-", "himBHs");
	if (!get_var(sh, "?"))
		bi_force_export(sh, "?", "0");
	bi_export(sh, "PS1", "$(directory)");
	if (!get_var(sh, "SHLVL"))
		bi_export(sh, "SHLVL", "0");
	if (!get_var(sh, "PWD"))
	{
		cwd = get_current_dir(sh);
		bi_export(sh, "PWD", cwd);
		bi_export(sh, "OLDPWD", cwd);
		free(cwd);
	}
}
