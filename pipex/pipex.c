/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:16:40 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/10 18:42:27 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/pipex.h"

static int	pipex(int fd, int argc, char **argv, char **envp)
{
	int	fdout[2];
	int	tube[2];
	int	i;

	i = 2;
	while (i < argc - 2)
	{
		pipe(tube);
		check_and_exec(envp, argv[i++], fd, tube);
		dup2(tube[0], fd);
		close(tube[1]);
		close(tube[0]);
	}
	fdout[1] = clean_make(argv[argc - 1], argv[0]);
	if (fdout[1] < 0)
		return (close(fd), 0);
	check_and_exec(envp, argv[i], fd, fdout);
	return (close(fd), close(fdout[1]), 1);
}

int	main(int argc, char	**argv, char **envp)
{
	int		fd;
	int		exit;

	if (argc != 5 || access(argv[1], R_OK) == -1)
		return (write(2, "Error.\n", 7), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (write(2, "Error.\nInvalid infile.\n", 22), 1);
	exit = pipex(fd, argc, argv, envp);
	return (wait(NULL), !exit);
}
