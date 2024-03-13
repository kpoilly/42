/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_funcs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:15:50 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/03/12 15:10:45 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_FUNCS_H
# define MINI_FUNCS_H

# include "structs.h"

// built-ins
# include "mini_built_ins.h"

//Signals.c
void	handle_sig_parent(int sig);
void	handle_sig_child(int sig);
void	ft_set_sig(void);
int		*ssig(void);

//Flags for main.c
void	prg_flags(t_shell *sh, int argc, char **argv);

// pipex

int		pipex(t_shell *sh);

// parsing

void	ft_resplit(t_shell *sh, int i, int *j, int *k);
int		unex_token(t_shell *sh, char *input);
void	lexer(t_shell *sh, char *prompt);
void	expander(t_shell *sh);
void	ft_quotes_and_expand(t_shell *sh, int i, int j);
int		ft_quotes_remover(char *str, int *k, int n);
int		ft_needs_expand(char *str);
int		ft_replace(t_shell *sh, int i, int *j, int *k);

// bash variables
void	set_underscore(t_shell *sh);
void	save_history(t_shell *sh);
void	load_history(t_shell *sh);
void	refresh_prompt(t_shell *sh);
void	mini_prompt(t_shell *sh);
char	*get_var(t_shell *sh, char *var);
int		get_env_index(t_shell *sh, char *var);

// utils

int		check_word(char *s, const char *word, int nl);
void	on_crash(t_shell *sh);
void	dup_envp(t_shell *sh, char **envp);

void	ft_perror(t_shell *sh, char *cmd, char *var, char *msg);

void	ft_tilde(t_shell *sh, char **cmd);
void	split_redirects(t_shell *sh);
char	**ft_split_skip(char *s, char c, char *skip);
char	*get_missing(char c);
char	*clean_add(char	*s, char c);
int		in_charset(char c, char	*set);
int		skip_skipset(char **s, int i);

void	ft_free_tabtab(char ***tab);
size_t	ft_tabtablen(char ***s);
void	print_tabtab(char ***tabtab);

void	ft_free_strtab(char **tab);
size_t	ft_strtablen(char **s);

void	free_sh(t_shell *sh);

// env

void	set_minimal_env(t_shell *sh);
char	*get_current_dir(t_shell *sh);

#endif
