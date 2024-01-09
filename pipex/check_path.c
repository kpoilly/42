/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:23:10 by marvin            #+#    #+#             */
/*   Updated: 2024/01/08 19:23:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./data/headers/pipex.h"

char	*is_valid(char *cmd, char **path_lst)
{
	int		i;
	char	*path;
	char	*bin;

	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	bin = ft_strjoin("/", cmd);
	i = 0;
	while (path_lst[i])
	{
		path = ft_strjoin(path_lst[i], bin);
		if (access(path, F_OK | X_OK) == 0)
			return (free(bin), path);
		free(path);
		i++;
	}
	free(bin);
	return (write(2, "Error.\nCommand \"", 17),
		ft_putstr_fd(cmd, 2),
		write(2, "\" not found.\n", 13), NULL);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	if (!n)
		return (0);
	i = 0;
	while ((s1[i] && s2[i] && s1[i] == s2[i]) && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static char	*ft_strnstr(char *big, char *little, int n)
{
	if (!ft_strlen(little))
		return ((char *)big);
	while (n > 0 && *big)
	{
		if (*big == little[0] && !ft_strncmp(big, little, ft_strlen(little))
			&& ft_strlen(little) <= n)
			return ((char *)big);
		big++;
		n--;
	}
	return (NULL);
}

char	**get_path(char	**envp)
{
	int	i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH=/home/", ft_strlen(envp[i])))
		i++;
	return (ft_split(envp[i] + 5, ':'));
}
