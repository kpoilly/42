/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:07:08 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/29 16:38:03 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_cd_no_arg(t_shell *sh)
{
	if (!get_var(sh, "HOME"))
		return (ft_perror(sh, "cd: ", NULL, "HOME not set"), NULL);
	return (ft_strdup(get_var(sh, "HOME")));
}

void	ft_tilde(t_shell *sh, char **cmd)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = -1;
	j = 1;
	if (!cmd[1][0] || (cmd[1][0] && cmd[1][0] != '~'))
		return ;
	if (cmd[1][0] && cmd[1][0] == '~' && !get_var(sh, "HOME"))
		return (ft_perror(sh, "cd: ", NULL, "HOME not set"));
	tmp = ft_calloc ((ft_strlen(get_var(sh, "HOME")) + \
	ft_strlen(cmd[1]) + 1), sizeof (char));
	if (!tmp)
		(ft_free_strtab(cmd), on_crash(sh));
	while (++i < ft_strlen(get_var(sh, "HOME")))
		tmp[i] = get_var(sh, "HOME")[i];
	while (cmd[1][j])
		tmp[i++] = cmd[1][j++];
	free(cmd[1]);
	cmd[1] = tmp;
}
