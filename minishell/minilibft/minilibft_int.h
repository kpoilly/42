/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft_int.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:19:53 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/13 13:43:40 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBFT_INT_H
# define MINILIBFT_INT_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int					ft_printf(const char *str, ...);
void				ft_putstr(char *str, size_t *z);
void				ft_putchar(unsigned char c, size_t *z);
void				ft_ptr(void *ptr, size_t *z);
void				ft_nbaseu(size_t nbr, char *base, size_t *z);
void				ft_nbase(int nbr, char *base, size_t *z);

typedef struct s_list
{
	struct s_list	*next;
	char			str[BUFFER_SIZE + 1];
	int				fd;
	bool			to_free;
}					t_list;

char				*get_next_line(int fd);
size_t				ft_strlen(char *str);
char				*ft_strjoin_gnl(char *s1, char *s2);
int					ft_while(t_list *file, char **line);

#endif