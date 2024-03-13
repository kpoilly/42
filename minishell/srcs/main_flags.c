/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:03:31 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/03/12 15:10:19 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_clear_history_file(void)
{
	if (access(HISTORY_FILE, F_OK | R_OK))
		return ;
	unlink(HISTORY_FILE);
}

void	prg_flags(t_shell *sh, int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return ;
	i = 0;
	while (++i < argc)
	{
		if (check_word(argv[i], "-quit", 0))
			exit(0);
		else if (check_word(argv[i], "--history-clear", 0) \
		|| check_word(argv[i], "--clear-history", 0))
			ft_clear_history_file();
		else if (check_word(argv[i], "-colors", 0))
			sh->colors = 1;
		else
		{
			ft_putstr_fd(argv[0], 2);
			ft_putstr_fd(": invalid option ", 2);
			ft_putstr_fd(argv[i], 2);
			ft_putstr_fd("\n", 2);
			exit(2);
		}
	}
}
