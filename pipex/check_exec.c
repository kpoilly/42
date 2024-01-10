/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:44:09 by marvin            #+#    #+#             */
/*   Updated: 2024/01/08 18:44:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/pipex.h"

int	execute_cmd(char **envp, char **args, int read_fd, int write_tube[2])
{
	int		process;

	process = fork();
	if (process == -1)
		return (0);
	if (!process)
	{
		close(write_tube[0]);
		dup2(write_tube[1], 1);
		dup2(read_fd, 0);
		close(write_tube[1]);
		close(read_fd);
		execve(args[0], args, envp);
	}
	return (1);
}

int	check_and_exec(char **envp, char *cmd, int read_fd, int write_tube[2])
{
	char	**path_lst;
	char	**args;
	char	*path;

	path_lst = get_path(envp);
	args = ft_split(cmd, ' ');
	path = is_valid(args[0], path_lst);
	ft_free(path_lst);
	free(args[0]);
	args[0] = path;
	if (!path)
		return (ft_free(args), 0);
	if (!execute_cmd(envp, args, read_fd, write_tube))
		return (ft_free(args), 0);
	return (ft_free(args), 1);
}

int	clean_make(char *filename, char *check_infile)
{
	int	fd;

	if (ft_strncmp(check_infile, "here_doc", 8) == 0)
		fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0666);
	else
	{
		unlink(filename);
		fd = open(filename, O_WRONLY | O_CREAT, 0666);
	}
	if (fd < 0)
		return (-1);
	return (fd);
}
