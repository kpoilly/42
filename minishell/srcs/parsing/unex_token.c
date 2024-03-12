/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unex_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:51:12 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/03/12 11:46:37 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_char(char *input, int *nb_char)
{
	int	i;

	i = 0;
	while (input[i] && !in_charset(input[i], "<>|\n"))
	{
		if (in_charset(input[i], "\"'"))
		{
			*nb_char = -1;
			return (0);
		}
		if (i == 0 || !in_charset(input[i], "<>&;()"))
			(*nb_char)++;
		i++;
	}
	if (input[i] && input[i + 1]
		&& in_charset(input[i], "<>")
		&& (input[i + 1] == input[i] || !i))
	{
		(*nb_char)++;
		i++;
	}
	return (i);	//rl_redisplay();
}

int	unex_token(t_shell *sh, char *input)
{
	int	nb_char;

	while (input && *input)
	{
		while (*input && *input == ' ')
			input++;
		if (!(*input))
			return (1);
		nb_char = 0;
		input += count_char(input, &nb_char);
		if (nb_char < 0)
			return (0);
		if (!nb_char)
		{
			ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
			if (*input)
				write(2, input, 1);
			else
				write(2, input - 1, 1);
			return (ft_putstr_fd("'\n", 2), bi_force_export(sh, "?", "2"), 1);
		}
		(*input && *(input + 1) && in_charset(*input, "<>|\n") && input++);
	}
	return (0);
}
