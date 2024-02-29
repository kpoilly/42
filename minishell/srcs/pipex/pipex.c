/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:50:14 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/29 15:40:54 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_end(int bi_ret, int *pid, int pip)
{
	close(pip);
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

static void	ft_putpipe_to_fone(int *pip, int outfile)
{
	close(pip[1]);
	if (outfile)
	{
		putpipe_to_fd(pip[0], outfile);
		close(outfile);
	}
}

static int	ft_init_file(int *file)
{
	file[0] = 0;
	file[1] = 0;
	file[2] = 2;
	return (0);
}

int	pipex(t_shell *sh)
{
	int	pip[2];
	int	i;
	int	file[3];
	int	pid[2];

	i = ft_init_file(file);
	if (pipe(pip) == -1)
		(perror("pipe"), exit(1));
	while (sh->input && sh->input[i] && sh->input[i][0])
	{
		ft_input_file(sh, file, pip, i);
		if (!sh->input || !sh->input[0] || !sh->input[0][0])
			return (close (pip[0]), 1);
		if ((int) ft_tabtablen(sh->input) - 1 == i)
			file[2]++;
		ft_putpipe_to_fone(pip, file[1]);
		ft_output_file(sh, file, i);
		pid[0] = fork_exec(sh, pip, &sh->input[i++][0], file);
		if (pid[0] == -1)
			return (127);
		if (file[0] && file[0] != 1)
			close(file[0]);
	}
	ft_putpipe_to_fone(pip, file[1]);
	return (ft_end(sh->bi_ret, pid, pip[0]));
}
