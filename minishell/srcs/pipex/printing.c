/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:11:48 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/01/18 17:50:04 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	putpipe_to_fd(int pip, int fd)
{
	char	*buf;

	buf = get_next_line(pip);
	if (!buf)
		return (-1);
	while (buf)
	{
		ft_putstr_fd(buf, fd);
		free(buf);
		buf = get_next_line(pip);
	}
	if (buf)
		free(buf);
	return (0);
}
