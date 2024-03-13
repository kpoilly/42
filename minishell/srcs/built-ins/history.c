/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:43:42 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/03/13 12:37:16 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	load_history(t_shell *sh)
{
	int		fd;
	char	*lines;

	sh->hist_path = ft_strjoin(get_var(sh, "PWD"), HISTORY_FILE);
	if (!sh->hist_path)
		on_crash(sh);
	if (access(sh->hist_path, F_OK | R_OK))
		return ;
	fd = open(sh->hist_path, O_RDONLY);
	if (fd < 0)
		on_crash(sh);
	sh->openf = fd;
	while (fd)
	{
		lines = get_next_line(fd);
		if (!lines)
			break ;
		lines[ft_strlen(lines) - 1] = 0;
		bi_add_history(sh, lines);
		free(lines);
	}
	close(fd);
	sh->openf = -1;
}

void	ft_history_cap(t_shell *sh);

void	save_history(t_shell *sh)
{
	int		fd;
	t_hist	*cursor;

	ft_history_cap(sh);
	fd = open(sh->hist_path, O_WRONLY | O_TRUNC | O_CREAT, 0710);
	if (fd < 0)
		return ;
	sh->openf = fd;
	cursor = sh->h;
	while (cursor && cursor->line)
	{
		ft_putstr_fd(cursor->line, fd);
		ft_putstr_fd("\n", fd);
		cursor = cursor->n;
	}
	close(fd);
	sh->openf = -1;
}

void	bi_add_history(t_shell *sh, char *prompt)
{
	t_hist	*cursor;

	add_history(prompt);
	if (!sh->h)
	{
		sh->h = malloc(sizeof (t_hist));
		if (!sh->h)
			on_crash(sh);
		sh->h->line = ft_strdup(prompt);
		if (!sh->h->line)
			on_crash(sh);
		sh->h->n = NULL;
		return ;
	}
	cursor = sh->h;
	while (cursor && cursor->n)
		cursor = cursor->n;
	cursor->n = malloc(sizeof (t_hist));
	if (!cursor->n)
		on_crash(sh);
	cursor->n->line = ft_strdup(prompt);
	if (!cursor->n->line)
		on_crash(sh);
	cursor->n->n = NULL;
	ft_history_cap(sh);
}

int	bi_history(t_shell *sh)
{
	size_t	i;
	t_hist	*cursor;

	i = 1;
	cursor = sh->h;
	while (cursor)
	{
		if (i < 10)
			ft_printf("   %i  %s\n", i, cursor->line);
		else if (i < 100)
			ft_printf("  %i  %s\n", i, cursor->line);
		else if (i < 1000)
			ft_printf(" %i  %s\n", i, cursor->line);
		else if (i < 10000)
			ft_printf("%i  %s\n", i, cursor->line);
		cursor = cursor->n;
		i++;
	}
	return (0);
}
