/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 07:37:40 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/11 15:54:32 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../GNL/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "./cub3D_struct.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>
# include <fcntl.h>

//utils
int				rgb_to_hex(int rgb[3]);
char			*ft_strjoin_char(char *hex, char a, char b);
char			*ft_strnstr(const char *big, const char *little, int n);
int				ft_strncmp(const char *s1, const char *s2, int n);
char			**ft_split(char *str, char *sep);
int				ft_atoi(const char *nptr);
void			free_tab(char **tab);
int				isempty(char *line);
float			dist(float ax, float ay, float bx, float by);
int				get_mapx(float x);
int				get_mapy(float y);
float			get_unmapx(int x);
float			get_unmapy(int y);
void			put_img_to_img(t_img dst, t_img src, int x, int y);
int				map_charset(char c);

//draw
void			draw_bg(t_data *data);
void			put_img_to_img(t_img dst, t_img src, int x, int y);
void			put_pixel(t_img img, int x, int y, int color);
unsigned int	get_pixel(t_img img, int x, int y);
void			draw_ray(t_data *data, float a, float endx, float endy);
void			draw_wall(t_data *data);

//map & data
char			**read_map(t_data *data, char *filename);
int				map_begin(char	*line);
int				*get_bg_colors(char *line);

//load & free
void			set_up(t_data *data);
void			set_up_mini(t_data *data);
void			set_up_img(t_data *data);
void			map_size(t_data *data);
t_img			load_img(t_data *data, t_img toload, int width, int height);
int				load_texture(t_data *data, t_img *img, char *path);
int				free_textures(t_data *data);
void			free_paths(t_data *data);
void			setup_img_anim(t_data *data);

//check error
int				check_error(t_data *data, char **map);
int				map_format(char *arg);

//events
int				no_event(t_data *data);
int				keypress(int keycode, t_data *data);
int				keyrelease(int keycode, t_data *data);
int				fire_exit(t_data *data, char **map);
int				destroy(t_data *data);
void			show_maps(t_data *data, int keycode);
void			switch_anim(t_data *data);

//minimap
void			draw_minimap(t_data *data);
void			draw_miniwall(t_data *data, int x, int y, int color);
void			draw_player(t_data *data);
void			draw_nose(t_data *data);

//micromap
void			draw_micromap(t_data *data);
void			draw_hand(t_data *data, t_img image, char *path);

//moves
void			moves_forback(t_data *data);
void			moves_leftright(t_data *data);
void			rotate(t_data *data);

//raycasting
void			raycasting(t_data *data);

#endif