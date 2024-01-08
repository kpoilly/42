/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:08:46 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/08 15:19:09 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

//utils
int		is_valid(char *cmd);
char	**ft_split(char const *s, char c);
void	ft_free(char **tab);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
int		ft_strlen(char *s);

#endif