/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:08:46 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/10 18:32:54 by kpoilly          ###   ########.fr       */
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
# include "../GNL/get_next_line.h"

//
int		get_infile(char *filename, char *limiter, int *skip);
int		check_and_exec(char **envp, char *cmd, int read_fd, int write_tube[2]);
int		execute_cmd(char **envp, char **args, int read_fd, int write_tube[2]);
int		clean_make(char *filename, char *check_infile);

//check path
char	**get_path(char	**envp);
char	*is_valid(char *cmd, char **path_lst);

//utils
char	**ft_split(char const *s, char c);
void	ft_free(char **tab);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strdup(char *src);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(char *s);
int		ft_tablen(char **tab);

#endif