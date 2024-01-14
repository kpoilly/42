/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:16:40 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/14 10:56:51 by marvin           ###   ########.fr       */
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
	int		i;
	int		fd;
	int		exit;
	int		skiph_d;
	char	**check_envp;

	if ((!ft_strncmp(argv[1], "here_doc", 8) && argc < 6) || argc < 5)
		return (write(2, "Error.\nToo few arguments.\n", 26), 1);
	if ((ft_strncmp(argv[1], "here_doc", 8) && access(argv[1], R_OK) == -1))
		return (write(2, "Error.\nInvalid infile.\n", 23), 1);
	check_envp = get_path(envp);
	if (!check_envp)
		return (write(2, "Error.\n", 7), 1);
	ft_free(check_envp);
	skiph_d = 0;
	fd = get_infile(argv[1], argv[2], &skiph_d);
	if (fd < 0)
		return (write(2, "Error.\nInvalid infile.\n", 22), 1);
	exit = pipex(fd, argc - skiph_d, argv + skiph_d, envp);
	i = 0;
	while (i++ < argc - skiph_d - 3)
		wait(NULL);
	return (!exit);
}
