/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:16:40 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/02 12:41:11 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/pipex.h"

int	main(int argc, char	**argv)
{
	char	*path;

	(void)argc;
	path = ft_strjoin("/bin/", argv[1]);
	execve(path, argv + 1, NULL);
	free(path);
	return (0);
}
