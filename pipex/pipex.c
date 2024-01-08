/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:16:40 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/08 15:22:15 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/pipex.h"

int	execute_cmd(char *cmd, int read_fd, int write_fd)
{
	char	**args;
	char	*path;
	int		process;

	args = ft_split(cmd, ' ');
	if (!is_valid(cmd))
		return (ft_free(args), 0);
	path = ft_strjoin("/bin/", args[0]);
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
	return (free(path), ft_free(args), 1);
}

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
		pipe(tube);
		if (!execute_cmd(argv[i++], fd, tube[1]))
			return (close(tube[1]), close(tube[0]), close(fd), 0);
		close(tube[1]);
		dup2(tube[0], fd);
		close(tube[0]);
	}
	unlink(argv[argc -1]);
	fdout = open(argv[argc - 1], O_WRONLY | O_CREAT, 0666);
	if (!execute_cmd(argv[i], fd, fdout))
		return (close(fdout), close(fd), 0);
	return (close(fdout), close(fd), wait(NULL), 0);
}
