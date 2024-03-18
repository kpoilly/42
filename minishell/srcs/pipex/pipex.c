/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:50:14 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/03/18 12:28:39 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_sigquit(void)
{
	struct sigaction	sa;
	struct sigaction	sa2;

	ft_bzero(&sa, sizeof(sa));
	ft_bzero(&sa2, sizeof(sa2));
	sa.sa_handler = &handle_sig_child;
	sa2.sa_handler = &handle_sig_child;
	sa.sa_flags = SA_RESTART;
	sa2.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &sa, NULL);
	sigaction(SIGINT, &sa2, NULL);
}

int	ft_end(int bi_ret, int *pid, int *pip, int *file)
{
	ft_sigquit();
	ft_putpipe_to_fone(pip, file);
	close(pip[0]);
	if (file[1] == -2)
		return (0);
	if (pid[0] != 0)
	{
		while (waitpid(pid[0], &pid[1], 0) < 0)
			;
		while (waitpid(-1, NULL, 0) != -1)
			;
		if (WIFEXITED(pid[1]))
			return (WEXITSTATUS(pid[1]));
		else if (WIFSIGNALED(pid[1]))
			return (WTERMSIG(pid[1]));
	}
	return (bi_ret);
}

void	ft_putpipe_to_fone(int *pip, int *file)
{
	close(pip[1]);
	if (file[1] && file[1] != -2)
	{
		putpipe_to_fd(pip[0], file[1]);
		close(file[1]);
	}
}

//file[2] values:
// 2 = start, 1 = end, 0 = middle, 3 = start + end
static int	ft_init_file(int *file, int *pid)
{
	file[0] = 0;
	file[1] = 0;
	file[2] = 2;
	pid[0] = 0;
	return (0);
}

int	pipex(t_shell *sh)
{
	int	pip[2];
	int	i;
	int	file[3];
	int	pid[2];

	i = ft_init_file(file, pid);
	if (pipe(pip) == -1)
		(perror("pipe"), exit(1));
	close(pip[1]);
	while (sh->input && sh->input[i] && sh->input[i][0])
	{
		if (ft_input_file(sh, file, pip, &i))
			return (close(pip[1]), close(pip[0]), sh->bi_ret);
		if ((int) ft_tabtablen(sh->input) - 1 == i)
			file[2]++;
		if (!ft_output_file(sh, file, i))
			pid[0] = fork_exec(sh, pip, &sh->input[i++][0], file);
		ft_putpipe_to_fone(pip, file);
		if (pid[0] == -1)
			return (127);
		if (file[0] && file[0] != 1)
			close(file[0]);
	}
	return (ft_end(sh->bi_ret, pid, pip, file));
}
