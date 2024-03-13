/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:34:56 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/03/12 13:50:12 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	heredocs(char *limiter, int *pip)
{
	char	*buf;
	char	*hd_file;
	char	*prev_file;

	buf = readline("heredoc> ");
	if (!buf)
		return ;
	hd_file = NULL;
	while (buf && limiter && !check_word(buf, limiter, 0))
	{
		prev_file = buf;
		buf = ft_strjoin(buf, "\n");
		free(prev_file);
		prev_file = hd_file;
		hd_file = ft_strjoin(hd_file, buf);
		if (prev_file)
			free(prev_file);
		if (!hd_file)
			return (free(buf));
		(free(buf), buf = readline("heredoc> "));
	}
	(ft_putstr_fd(hd_file, pip[1]), close(pip[1]));
	(free(buf), free(hd_file));
}
