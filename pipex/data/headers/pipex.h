/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:08:46 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/08 19:40:11 by marvin           ###   ########.fr       */
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

//
int		check_and_exec(char **path_lst, char *cmd, int read_fd, int write_fd);
int		execute_cmd(char *path, char **args, int read_fd, int write_fd);
int		clean_make(char *filename);

//check path
char	**get_path(char	**envp);
char	*is_valid(char *cmd, char **path_lst);

//utils
char	**ft_split(char const *s, char c);
void	ft_free(char **tab);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(char *s);

#endif