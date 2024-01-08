/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:16:40 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/08 14:55:13 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/pipex.h"

int	execute_cmd(char *cmd, int read_fd, int write_fd)
{
	char	**args;
	char	*path;
	int		process;

	args = ft_split(cmd, ' ');
	path = ft_strjoin("/bin/", args[0]);
	process = fork();
	if (!process)
	{
		dup2(write_fd, 1);
		dup2(read_fd, 0);
		close(write_fd);
		close(read_fd);
		execve(path, args, NULL);
	}
	free(path);
	ft_free(args);
	return (0);
}

// int	is_valid(char *cmd)
// {
// 	(void)cmd;
// 	return (1);
// }

// int	check_and_exec(char	*cmd, int fd, int (*tube)[2])
// {
// 	char	**args;

// 	args = ft_split(cmd, ' ');
// 	if (!is_valid(args[0]))
// 		return (ft_free(args), 0);
// 	pipe(tube);
// 	execute_cmd(args, fd, tube[1]);
// 	close(tube[1]);
// 	dup2(tube[0], fd);
// 	close(tube[0]);
// 	return (ft_free(args), 1);
// }

int	main(int argc, char	**argv)
{
	int	fd;
	int	fdout;
	int	tube[2];
	int	i;

	if (argc < 4)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	i = 2;
	while (i < argc - 2)
	{
		// if (!check_and_exec(argv[i++], fd, &tube))
		// 	return (close(fd), 0);
		pipe(tube);
		execute_cmd(argv[i++], fd, tube[1]);
		close(tube[1]);
		dup2(tube[0], fd);
		close(tube[0]);
	}
	unlink(argv[argc -1]);
	fdout = open(argv[argc - 1], O_WRONLY | O_CREAT, 0666);
	// if (!check_and_exec(argv[i], fd, &tube))
	// 	return (close(fd), 0);
	execute_cmd(argv[i], fd, fdout);
	close(fdout);
	close(fd);
	wait(NULL);
	return (0);
}
