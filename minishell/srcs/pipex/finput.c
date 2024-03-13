/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finput.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:30:28 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/03/13 14:09:59 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_hereing_doc(t_shell *sh, int *pip, int i)
{
	int	j;
	int	ret;

	ret = 0;
	j = 0;
	sh->int_save = 0;
	while (sh->input && sh->input[i][j])
	{
		if (sh->input[i] && sh->input[i][j] && sh->input[i][j + 1]
				&& check_word(sh->input[i][j], "<", 0))
			sh->int_save = 0;
		if (sh->input[i] && sh->input[i][j] && sh->input[i][j + 1]
				&& check_word(sh->input[i][j], "<<", 0))
		{
			close(pip[0]);
			if (pipe(pip) == -1)
				(perror("pipe"), exit(1));
			(heredocs(sh->input[i][j + 1], pip), ft_remove_file(sh, i, j));
			ret = 1;
			sh->int_save = 1;
		}
		else
			j++;
	}
	return (ret);
}

static int	ft_access_file(t_shell *sh, int *file, int *i, int j)
{
	if (file[0] > 1)
		close(file[0]);
	if (access(sh->input[*i][j + 1], R_OK))
	{
		ft_perror(sh, NULL, sh->input[*i][j + 1], \
		": No such file or directory");
		ft_remove_file(sh, *i, j);
		if (!sh->int_save)
			file[0] = open("/dev/null", O_RDONLY);
		return (sh->bi_ret = 1, 1);
	}
	if (!sh->int_save)
		file[0] = open(sh->input[*i][j + 1], O_RDONLY);
	if (file[0] == -1)
	{
		perror("open");
		exit(1);
	}
	ft_remove_file(sh, *i, j);
	return (0);
}

int	ft_input_file(t_shell *sh, int *file, int *pip, int *i)
{
	int	j;
	int	ret;

	j = 0;
	ret = 0;
	file[0] = ft_hereing_doc(sh, pip, *i);
	while (sh->input && sh->input[*i][j])
	{
		if (sh->input && sh->input[*i] && sh->input[*i][j] && \
			sh->input[*i][j + 1] && check_word(sh->input[*i][j], "<", 0))
		{
			if (ft_access_file(sh, file, i, j))
			{
				if (sh->input[*i + 1] && j != 0)
					return ((*i)++, file[2] = 0, \
					ft_input_file(sh, file, pip, i));
				return (1);
			}
		}
		else
			j++;
	}
	return (ret);
}
