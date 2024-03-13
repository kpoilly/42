/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:54:57 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/03/13 13:37:37 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Put '~' instead of $HOME
char	*home_shortener(t_shell *sh)
{
	char	*short_dir;
	char	*dir;

	dir = ft_strdup(get_var(sh, "PWD"));
	if (!dir)
		on_crash(sh);
	if (!get_var(sh, "HOME") || \
	ft_strlen(get_var(sh, "HOME")) > ft_strlen(dir) || \
	ft_strncmp(get_var(sh, "HOME"), dir, ft_strlen(get_var(sh, "HOME"))))
		return (dir);
	if (!ft_strnstr(dir, get_var(sh, "HOME"), ft_strlen(dir)))
		return (dir);
	short_dir = ft_strjoin("~", ft_strnstr(dir, get_var(sh, "HOME"), \
	ft_strlen(dir)) + ft_strlen(get_var(sh, "HOME")));
	free(dir);
	if (!short_dir)
		on_crash(sh);
	return (short_dir);
}

//Issues to regler soon plz
void	refresh_prompt(t_shell *sh)
{
	char	*semi_prompt;
	char	*short_home;

	if (sh->prompt)
		free(sh->prompt);
	sh->prompt = NULL;
	short_home = home_shortener(sh);
	if (sh->colors)
		semi_prompt = ft_strjoin(PROMPT_START, short_home);
	else
		semi_prompt = ft_strjoin("[", short_home);
	free(short_home);
	if (!semi_prompt)
		on_crash(sh);
	if (sh->colors)
		sh->prompt = ft_strjoin(semi_prompt, PROMPT_END);
	else
		sh->prompt = ft_strjoin(semi_prompt, "] ");
	if (!sh->prompt)
		(free(semi_prompt), on_crash(sh));
	free(semi_prompt);
}

static void	errno_pipex(t_shell *sh)
{
	char	*errno_str;

	errno_str = ft_itoa(pipex(sh));
	if (!errno_str)
		on_crash(sh);
	bi_force_export(sh, "?", errno_str);
	free(errno_str);
}

static void	ft_sigint_return(t_shell *sh)
{
	int	*sigint_ret;

	sigint_ret = ssig();
	if (*sigint_ret == 130)
	{
		bi_force_export(sh, "?", "130");
		*sigint_ret = 0;
	}
}

void	mini_prompt(t_shell *sh)
{
	char	*input;

	load_history(sh);
	while (1)
	{
		(set_minimal_env(sh), ft_set_sig());
		input = readline(sh->prompt);
		if (unex_token(sh, input))
			(bi_add_history(sh, input), save_history(sh), free(input));
		else if (input && ft_strlen(input))
		{
			ft_sigint_return(sh);
			bi_add_history(sh, input);
			save_history(sh);
			lexer(sh, input);
			split_redirects(sh);
			expander(sh);
			errno_pipex(sh);
			set_underscore(sh);
		}
		else if (!input)
			(printf("exit\n"), on_crash(sh));
		else
			free(input);
	}
}
