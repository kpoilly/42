/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:09:29 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/03/12 14:58:52 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
		free(str[i++]);
	if (str)
		free(str);
}

void	print_error(char *msg, int exit_code)
{
	perror(msg);
	if (exit_code >= 0)
		exit(exit_code);
}

void	ft_remove_file(t_shell *sh, int i, int j)
{
	int	k;

	if (sh->input[i][j])
		free(sh->input[i][j]);
	sh->input[i][j] = NULL;
	if (sh->input[i][j + 1])
		free(sh->input[i][j + 1]);
	sh->input[i][j + 1] = NULL;
	k = 2;
	while (sh->input[i][j + k])
	{
		sh->input[i][j + k - 2] = sh->input[i][j + k];
		sh->input[i][j + k] = NULL;
		k++;
	}
}
