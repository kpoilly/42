/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:54:57 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/29 16:08:51 by kpoilly          ###   ########.fr       */
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
	semi_prompt = ft_strjoin(PROMPT_START, short_home);
	free(short_home);
	if (!semi_prompt)
		on_crash(sh);
	sh->prompt = ft_strjoin(semi_prompt, PROMPT_END);
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
	bi_export(sh, "?", errno_str);
	free(errno_str);
}

static int	unex_token(char *input)
{
	while (*input && *input == ' ')
		input++;
	return (*input == '|');
}

void	mini_prompt(t_shell *sh)
{
	char	*input;

	load_history(sh);
	while (1)
	{
		set_minimal_env(sh);
		ft_set_sig();
		input = readline(sh->prompt);
		if (unex_token(input))
			ft_putstr_fd("syntax error near unexpected token `|'\n", 2);
		else if (input && ft_strlen(input))
		{
			bi_add_history(sh, input);
			save_history(sh);
			lexer(sh, input);
			split_redirects(sh);
			expander(sh);
			set_underscore(sh);
			errno_pipex(sh);
		}
		else if (!input)
			(printf("exit\n"), on_crash(sh));
		else
			free(input);
	}
}
