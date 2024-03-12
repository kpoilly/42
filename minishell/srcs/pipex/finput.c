/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finput.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:30:28 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/03/12 10:45:08 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_hereing_doc(t_shell *sh, int *pip, int i, int j)
{
	int	k;

	k = j;
	close(pip[0]);
	if (pipe(pip) == -1)
		(perror("pipe"), exit(1));
	heredocs(sh->input[i][j + 1], pip);
	if (sh->input[i][j])
		free(sh->input[i][j]);
	sh->input[i][j] = NULL;
	if (sh->input[i][j + 1])
		free(sh->input[i][j + 1]);
	sh->input[i][j + 1] = NULL;
	while (sh->input[i][j + 2])
	{
		sh->input[i][j] = sh->input[i][j + 2];
		sh->input[i][j + 2] = NULL;
		j++;
	}
	return (0);
}

static int	ft_redirect_nothing_else(t_shell *sh, int *file, int i)
{
	if (!sh->input[i] || !sh->input[i][0])
	{
		close(file[0]);
		file[0] = 0;
		sh->bi_ret = 0;
		return (1);
	}
	return (0);
}

static void	ft_input_open(t_shell *sh, int *file, int *i, int j)
{
	file[0] = open(sh->input[*i][j + 1], O_RDONLY);
	if (file[0] == -1)
	{
		perror("open");
		exit(1);
	}
}

static int	ft_access_file(t_shell *sh, int *file, int *i, int j)
{
	if (access(sh->input[*i][j + 1], R_OK))
		return (perror("file"), sh->bi_ret = 1, 1);
	ft_input_open(sh, file, i, j);
	ft_remove_input_file(sh, *i, j);
	return (0);
}

int	ft_input_file(t_shell *sh, int *file, int *pip, int *i)
{
	int	j;

	j = -1;
	while (sh->input && sh->input[*i][++j])
	{
		if (sh->input[*i] && sh->input[*i][j] && sh->input[*i][j + 1]
				&& check_word(sh->input[*i][j], "<<", 0))
		{
			if (!ft_hereing_doc(sh, pip, *i, j) && !sh->input[*i][0])
				return (sh->bi_ret = 0, 1);
			return (file[0] = 1, 0);
		}
		else if (sh->input && sh->input[*i] && sh->input[*i][j] && \
			sh->input[*i][j + 1] && check_word(sh->input[*i][j], "<", 0))
		{
			if (ft_access_file(sh, file, i, j))
				return (1);
			if (ft_redirect_nothing_else(sh, file, *i) && sh->input[*i + 1])
				return (file[2] = 3, (*i)++, ft_input_file(sh, file, pip, i));
			if (!sh->input[*i + 1] && !file[0])
				return (sh->bi_ret = 0, 1);
			return (0);
		}
	}
	return (file[0] = 0, 0);
}
