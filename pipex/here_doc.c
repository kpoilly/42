/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:53:58 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/09 12:24:16 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/pipex.h"

static int	get_here_doc(char *limiter)
{
	int		tube[2];
	char	*input;

	pipe(tube);
	input = get_next_line(0);
	while (ft_strncmp(input, limiter, ft_strlen(limiter)))
	{
		free(input);
		input = get_next_line(0);
		ft_putstr_fd(input, tube[1]);
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
	if (access(filename, R_OK) == -1)
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}
