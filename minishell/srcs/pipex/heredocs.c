/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:34:56 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/29 14:08:38 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	heredocs(char *limiter, int *pip)
{
	char	*buf;
	char	*hd_file;
	char	*prev_file;

	ft_printf("heredoc> ");
	buf = get_next_line(0);
	if (!buf)
		return ;
	hd_file = NULL;
	while (buf && limiter && !check_word(buf, limiter, 1))
	{
		prev_file = hd_file;
		hd_file = ft_strjoin(hd_file, buf);
		if (prev_file)
			free(prev_file);
		if (!hd_file)
			return (free(buf));
		free(buf);
		ft_printf("heredoc> ");
		buf = get_next_line(0);
	}
	free(buf);
	ft_putstr_fd(hd_file, pip[1]);
	free(hd_file);
}
