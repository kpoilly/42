/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:16:40 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/14 10:51:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/pipex.h"

static int	pipex(int fd, int argc, char **argv, char **envp)
{
	int	fdout[2];
	int	tube[2];
	int	fdtemp;
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
	pipe(fdout);
	fdtemp = clean_make(argv[argc - 1], argv[0]);
	dup2(fdtemp, fdout[1]);
	close(fdtemp);
	if (fdout[1] < 0)
		return (close(fd), 0);
	check_and_exec(envp, argv[i], fd, fdout);
	return (close(fd), close(fdout[0]), close(fdout[1]), 1);
}

int	main(int argc, char	**argv, char **envp)
{
	int		fd;
	int		exit;
	char	**check_envp;

	if (argc != 5)
		return (write(2, "Error.\nToo few arguments.\n", 26), 1);
	if (access(argv[1], R_OK) == -1)
		return (write(2, "Error.\nPermission denied.\n", 26), 1);
	check_envp = get_path(envp);
	if (!check_envp)
		return (write(2, "Error.\nNo Path variable in envp.\n", 33), 1);
	ft_free(check_envp);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (write(2, "Error.\nInvalid infile.\n", 22), 1);
	exit = pipex(fd, argc, argv, envp);
	return (wait(NULL), wait(NULL), !exit);
}
