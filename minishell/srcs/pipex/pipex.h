/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:04:02 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/03/12 14:59:31 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "minilibft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include "structs.h"
# include "minishell.h"
# include <signal.h>
# include <poll.h>

int		fork_exec(t_shell *sh, int *pip, char **full_cmd, int *file);
char	*absolute_path(t_shell *sh, char **cmd_str, char **envp);
int		putpipe_to_fd(int pip, int fd);
void	heredocs(char *limiter, int *pip);
void	ft_free(char **str);
void	print_error(char *msg, int plz_exit);
void	ft_remove_file(t_shell *sh, int i, int j);

void	ft_putpipe_to_fone(int *pip, int *file);
int		ft_end(int bi_ret, int *pid, int *pip, int *file);
int		ft_output_file(t_shell *sh, int *file, int i);
int		ft_input_file(t_shell *sh, int *file, int *pip, int *i);

#endif
