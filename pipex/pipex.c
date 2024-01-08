/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:16:40 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/08 20:09:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/pipex.h"

static int	pipex(int argc, char **argv, char **path_lst)
{
	int	fd;
	int	fdout;
	int	tube[2];
	int	i;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	i = 2;
	while (i < argc - 2)
	{
		pipe(tube);
		if (check_and_exec(path_lst, argv[i++], fd, tube[1]))
			dup2(tube[0], fd);
		else
			dup2(0, fd);
		close(tube[1]);
		close(tube[0]);
	}
	fdout = clean_make(argv[argc - 1]);
	if (fdout < 0)
		return (close(fd), 0);
	check_and_exec(path_lst, argv[i], fd, fdout);
	return (close(fdout), close(fd), 1);
}

int	main(int argc, char	**argv, char **envp)
{
	int		exit;
	char	**path_lst;

	if (argc < 4)
		return (1);
	path_lst = get_path(envp);
	exit = pipex(argc, argv, path_lst);
	return (wait(NULL), ft_free(path_lst), !exit);
}
