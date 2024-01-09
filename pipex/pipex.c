/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:16:40 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/09 17:13:21 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/pipex.h"

static int	pipex(int fd, char **argv, char **path_lst)
{
	int	fdout;
	int	tube[2];
	int	argc;
	int	i;

	argc = ft_tablen(argv);
	i = 2;
	while (i < argc - 2)
	{
		pipe(tube);
		check_and_exec(path_lst, argv[i++], fd, tube[1]);
		dup2(tube[0], fd);
		close(tube[1]);
		close(tube[0]);
	}
	fdout = clean_make(argv[argc - 1], argv[0]);
	if (fdout < 0)
		return (close(fd), 0);
	check_and_exec(path_lst, argv[i], fd, fdout);
	return (close(fd), close(fdout), 1);
}

int	main(int argc, char	**argv, char **envp)
{
	int		fd;
	char	**path_lst;
	int		exit;

	if (argc != 5 || access(argv[1], R_OK) == -1)
		return (write(2, "Error.\n", 7), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	if (fd < 0)
		return (write(2, "Error.\nInvalid infile.\n", 22), 1);
	path_lst = get_path(envp);
	exit = pipex(fd, argv, path_lst);
	return (wait(NULL), close(fd), ft_free(path_lst), !exit);
}
