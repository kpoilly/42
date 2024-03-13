/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:15:45 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/03/13 13:37:16 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//file[2] values:
// 2 = start, 1 = end, 0 = middle, 3 = start + end
static void	ft_child_fork(int *pip, int *file, int prev_pip)
{
	if (file[0] > 1)
		(dup2(file[0], 0), close(prev_pip));
	else if (((!file[0] && (file[2] == 1 || file[2] == 0)) || file[0] == 1))
		dup2(prev_pip, 0);
	else
		close(prev_pip);
	close(pip[0]);
	if (((file[2] != 3 && file[2] != 1) || (file[1] > 0)))
		dup2(pip[1], 1);
	else
		close(pip[1]);
	if (file[1] > 0)
		close(file[1]);
}

static void	ft_execve(char *abs_path, char **full_cmd, t_shell *sh)
{
	struct sigaction	sa;
	struct sigaction	sa2;

	ft_bzero(&sa, sizeof(sa));
	ft_bzero(&sa2, sizeof(sa2));
	sa.sa_handler = SIG_DFL;
	sa2.sa_handler = SIG_DFL;
	sa.sa_flags = SA_RESTART;
	sa2.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa2, NULL);
	if (is_built_in(abs_path, -1))
	{
		free(abs_path);
		exit(built_ins(sh, full_cmd));
	}
	execve(abs_path, &full_cmd[0], sh->envp);
	perror(full_cmd[1]);
	exit(-1);
}

static int	ft_fork(int *pip, char *abs_path, char **full_cmd, int *file)
{
	int		fid;
	int		prev_pip;

	prev_pip = pip[0];
	if (pipe(pip) == -1)
		return (perror("pipe"), close(prev_pip), ft_free(full_cmd),
			free(abs_path), -1);
	if (file[1] == -2)
		return (-100);
	fid = fork();
	if (fid == -1)
		return (free(abs_path), ft_free(full_cmd), close(prev_pip),
			close(pip[1]), close(pip[0]), -1);
	if (!fid)
		ft_child_fork(pip, file, prev_pip);
	return (fid);
}

int	fork_exec(t_shell *sh, int *pip, char **full_cmd, int *file)
{
	char	*abs_path;
	int		fid;
	int		prev_pip;

	fid = 0;
	sh->bi_ret = 0;
	if (!full_cmd[0])
		return (close(pip[0]), 0);
	abs_path = absolute_path(sh, full_cmd, sh->envp);
	if (!abs_path)
		return (close(pip[0]), -1);
	prev_pip = pip[0];
	if (is_built_in(abs_path, 0) && !sh->input[1])
		(free(abs_path), close(pip[0]), sh->bi_ret = built_ins(sh, full_cmd));
	else
	{
		fid = ft_fork(pip, abs_path, full_cmd, file);
		if (fid == -1)
			return (-1);
		else if (!fid)
			ft_execve(abs_path, full_cmd, sh);
		free(abs_path);
	}
	return (close(prev_pip), file[2] = 0, fid);
}
