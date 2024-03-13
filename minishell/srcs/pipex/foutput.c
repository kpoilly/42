/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foutput.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:29:38 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/03/13 12:41:09 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_open_out(t_shell *sh, int *file, int i, int j)
{
	char	*fpath;
	char	*fflags;

	if (i < 0)
		return ;
	fpath = sh->input[i][j + 1];
	fflags = sh->input[i][j];
	if (file[1])
		close(file[1]);
	if (fflags && check_word(fflags, ">", 0) && fpath)
		file[1] = open(fpath, O_WRONLY | O_TRUNC | O_CREAT, 0710);
	else if (fflags && check_word(fflags, ">>", 0) && fpath)
		file[1] = open(fpath, O_WRONLY | O_APPEND | O_CREAT, 0710);
	ft_remove_file(sh, i, j);
	if (file[1] == -1)
	{
		perror("open");
		sh->bi_ret = 1;
	}
}

int	ft_output_file(t_shell *sh, int *file, int i)
{
	int	j;

	j = 0;
	file[1] = 0;
	sh->bi_ret = 0;
	while (sh->input && sh->input[i][j])
	{
		if (sh->input[i][j + 1] && (check_word(sh->input[i][j], ">", 0) || \
		check_word(sh->input[i][j], ">>", 0)))
			ft_open_out(sh, file, i, j);
		else
			j++;
	}
	return (sh->bi_ret);
}
