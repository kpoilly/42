/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:32:31 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/03/12 15:10:51 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_init_sh(t_shell *sh)
{
	ft_bzero(sh, sizeof(sh));
	sh->hist_path = NULL;
	sh->prompt = NULL;
	sh->input = NULL;
	sh->envp = NULL;
	sh->openf = -1;
	sh->colors = 0;
	sh->bi_ret = 0;
	sh->h = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	sh;
	char	*shlvl;

	ft_init_sh(&sh);
	prg_flags(&sh, argc, argv);
	dup_envp(&sh, envp);
	if (!get_var(&sh, "PATH"))
		bi_export(&sh, "PATH", \
		"/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin");
	set_minimal_env(&sh);
	shlvl = ft_itoa(ft_atoi(get_var(&sh, "SHLVL")) + 1);
	if (!shlvl)
		on_crash(&sh);
	bi_export(&sh, "SHLVL", shlvl);
	free(shlvl);
	bi_force_export(&sh, "0", argv[0]);
	refresh_prompt(&sh);
	mini_prompt(&sh);
	return (0);
}
