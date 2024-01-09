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

int	execute_cmd(char *path, char **args, int read_fd, int write_fd)
{
	int		process;

	process = fork();
	if (process == -1)
		return (0);
	if (!process)
	{
		dup2(write_fd, 1);
		dup2(read_fd, 0);
		close(write_fd);
		close(read_fd);
		execve(path, args, NULL);
	}
	// waitpid(process, NULL, 0);
	return (1);
}

int	check_and_exec(char **path_lst, char *cmd, int read_fd, int write_fd)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	path = is_valid(args[0], path_lst);
	if (!path)
		return (ft_free(args), 0);
	if (!execute_cmd(path, args, read_fd, write_fd))
		return (ft_free(args), free(path), 0);
	return (ft_free(args), free(path), 1);
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
