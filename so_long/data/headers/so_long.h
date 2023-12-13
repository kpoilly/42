/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:57:41 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/13 16:34:19 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "get_next_line.h"
# include "ft_printf.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_mlx {
	void	*ptr;
	void	*win;
}				t_mlx;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}				t_img;

//map setup and primary functions
char			**get_map(char *filename, int *nb_line, int *nb_col);
int				check_error(char **map);

//tile transparency
unsigned int	get_pixel(t_img img, int x, int y);
void			put_pixel(t_img img, int x, int y, int color);
void			put_img_to_img(t_img dst, t_img src, int x, int y);

#endif