/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foutput.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:29:38 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/29 11:49:03 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_output_file(t_shell *sh, int *file, int i)
{
	char	*fpath;
	char	*fflags;
	int		last_word;

	file[1] = 0;
	last_word = ft_strtablen(sh->input[i]) - 1;
	if (last_word < 1 || i < 0)
		return ;
	fpath = sh->input[i][last_word];
	fflags = sh->input[i][last_word - 1];
	if (fflags && check_word(fflags, ">", 0) && fpath)
		file[1] = open(fpath, O_WRONLY | O_TRUNC | O_CREAT, 0710);
	else if (fflags && check_word(fflags, ">>", 0) && fpath)
		file[1] = open(fpath, O_WRONLY | O_APPEND | O_CREAT, 0710);
	else
		return ;
	free(fpath);
	free(fflags);
	sh->input[i][last_word] = NULL;
	sh->input[i][last_word - 1] = NULL;
	if (file[1] == -1)
		(perror("open"), exit(1));
}
