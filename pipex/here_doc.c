/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:53:58 by kpoilly           #+#    #+#             */
/*   Updated: 2024/02/06 08:36:13 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/pipex.h"

static int	get_here_doc(char *limiter)
{
	int		tube[2];
	char	*input;

	if (!*limiter)
		limiter = "\n";
	pipe(tube);
	write(1, "heredoc> ", 9);
	input = get_next_line(0);
	while (ft_strncmp(input, ft_strjoin(limiter, "\n"), ft_strlen(limiter) + 1))
	{
		ft_putstr_fd(input, tube[1]);
		free(input);
		write(1, "heredoc> ", 9);
		input = get_next_line(0);
	}
	close(tube[1]);
	return (free(input), tube[0]);
}

int	get_infile(char *filename, char *limiter, int *skip)
{
	int	fd;

	if (ft_strncmp(filename, "here_doc", 9) == 0)
	{
		*skip = 1;
		return (get_here_doc(limiter));
	}
	if (access(filename, F_OK | R_OK) == -1)
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}
