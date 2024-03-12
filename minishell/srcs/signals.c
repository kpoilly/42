/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:57:21 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/03/07 14:30:09 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*ssig(void)
{
	static int	val = 0;

	return (&val);
}

void	handle_sig(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		*(ssig()) = 130;
	}
	else if (sig == SIGQUIT)
		ft_putstr_fd("Quit (core dumped)\n", 2);
	return ;
}

void	ft_set_sig(void)
{
	struct sigaction	sa;
	struct sigaction	sa2;

	ft_bzero(&sa, sizeof(sa));
	ft_bzero(&sa2, sizeof(sa2));
	sa.sa_handler = &handle_sig;
	sa2.sa_handler = SIG_IGN;
	sa.sa_flags = SA_RESTART;
	sa2.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa2, NULL);
}
