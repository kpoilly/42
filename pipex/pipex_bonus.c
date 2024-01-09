/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:16:40 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/09 17:30:28 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/pipex.h"

static int	pipex(int fd, int argc, char **argv, char **envp)
{
	int	fdout;
	int	tube[2];
	int	i;

	i = 2;
	while (i < argc - 2)
	{
		pipe(tube);
		check_and_exec(envp, argv[i++], fd, tube[1]);
		dup2(tube[0], fd);
		close(tube[1]);
		close(tube[0]);
	}
	fdout = clean_make(argv[argc - 1], argv[0]);
	if (fdout < 0)
		return (0);
	check_and_exec(envp, argv[i], fd, fdout);
	return (close(fdout), 1);
}

int	main(int argc, char	**argv, char **envp)
{
	int		fd;
	int		exit;
	int		skiph_d;

	if (argc < 5)
		return (write(2, "Error.\n", 7), 1);
	skiph_d = 0;
	fd = get_infile(argv[1], argv[2], &skiph_d);
	if (fd < 0)
		return (write(2, "Error.\nInvalid infile.\n", 22), 1);
	exit = pipex(fd, argc - skiph_d, argv + skiph_d, envp);
	return (wait(NULL), close(fd), !exit);
}
