/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finput.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:30:28 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/29 15:26:28 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_hereing_doc(t_shell *sh, int *pip, int i, int j)
{
	heredocs(sh->input[i][j + 1], pip);
	ft_remove_input_file(sh, i, j);
	if (!sh->input[i][j] && j == 0)
	{
		sh->input[i][j] = ft_strdup("cat");
		if (!sh->input[i][j])
			on_crash(sh);
	}
}

void	ft_input_file(t_shell *sh, int *file, int *pip, int i)
{
	int	j;

	j = 0;
	file[0] = 0;
	while (sh->input && sh->input[i][j])
	{
		if (sh->input && sh->input[i] && sh->input[i][j] && sh->input[i][j + 1]
				&& check_word(sh->input[i][j], "<<", 0))
			return (ft_hereing_doc(sh, pip, i, j), file[0] = 1, (void) NULL);
		else if (sh->input && sh->input[i] && sh->input[i][j] && \
			sh->input[i][j + 1] && check_word(sh->input[i][j], "<", 0))
		{
			if (access(sh->input[i][j + 1], R_OK))
				(perror("file"), exit(1));
			file[0] = open(sh->input[i][j + 1], O_RDONLY);
			if (file[0] == -1)
				(perror("open"), exit(1));
			ft_remove_input_file(sh, i, j);
			dup2(file[0], pip[0]);
			return ;
		}
		j++;
	}
}
