/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:29:04 by kpoilly           #+#    #+#             */
/*   Updated: 2023/11/19 15:05:02 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
int		isnewline(char *str, char c);
char	*get_line(char **next_line, int pos);
char	*end_of_file(char **next_line);

int		ft_strlen(char *s);
int		ft_atoi(const char *nptr);
char	*ft_strndup(char *src, int n);
char	*ft_strjoin(char *s1, char *s2);
void	ft_bzero(void *s, size_t n);

#endif