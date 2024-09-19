/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 07:37:40 by kpoilly           #+#    #+#             */
/*   Updated: 2024/09/17 19:32:44 by kpoilly          ###   ########.fr       */
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
char			*ft_itoa(int n);
char			*ft_strndup(char *src, int n);
void			free_tab(char **tab);
int				isempty(char *line);
float			dist(float ax, float ay, float bx, float by);
int				get_mapx(float x);
int				get_mapy(float y);
float			get_unmapx(int x);
float			get_unmapy(int y);
void			put_img_to_img(t_img dst, t_img src, int x, int y);

//draw
void			draw_bg(t_data *data);
void			put_img_to_img(t_img dst, t_img src, int x, int y);
void			put_pixel(t_img img, int x, int y, int color);
unsigned int	get_pixel(t_img img, int x, int y);
void			draw_ray(t_data *data, float a, float endx, float endy);
void			draw_wall(t_data *data);
void			draw_lol(t_data *data);
void			draw_obj(t_data *data);
void			draw_door(t_data *data);
void			draw_walldoor(t_data *data);

//map & data
char			**read_map(t_data *data, char *filename);
int				map_begin(char	*line);
int				*get_bg_colors(char *line);

//load & free
void			set_up(t_data *data);
void			set_up_mini(t_data *data);
void			set_up_img(t_data *data);
t_img			load_img(t_data *data, t_img toload, int width, int height);
int				load_texture(t_data *data, t_img *img, char *path);
int				free_textures(t_data *data);
void			free_paths(t_data *data);
void			setup_img_anim(t_data *data);
void			free_anim(t_data *data, t_anim *texture, int loop);
void			free_text_extra(t_data *data);

//check error
int				check_error(t_data *data, char **map);
int				map_format(char *arg);
int				map_charset(char c);
int				door_placement(char	**tab);

//events
int				no_event(t_data *data);
int				keypress(int keycode, t_data *data);
int				keyrelease(int keycode, t_data *data);
int				fire_exit(t_data *data, char **map);
int				destroy(t_data *data);
void			show_maps(t_data *data, int keycode);
void			switch_anim(t_data *data);
void			doors(t_data *data);
void			mouse(t_data *data);
void			event_speed(t_data *data, int keycode);
//minimap
void			draw_minimap(t_data *data);
void			draw_miniwall(t_data *data, int x, int y, int color);
void			draw_player(t_data *data);
void			draw_nose(t_data *data);

//micromap
void			draw_micromap(t_data *data);
void			draw_hand(t_data *data, t_img image, char *path);
void			draw_microplayer(t_data *data, int x, int y, int color);
void			draw_microthing(t_data *data, int mapx, int mapy, float y);
void			draw_microwall(t_data *data, int x, int y, int color);

//moves
void			moves_forback(t_data *data);
void			moves_leftright(t_data *data);
void			rotate(t_data *data);

//raycasting
void			raycasting(t_data *data);

//doors
void			set_door_list(t_data *data);
void			add_door(t_data *data, int mapy, int mapx, int id);
int				count_in_tab(char **tab, char c);
t_door			*get_door(t_data *data, float x, float y);
void			open_doors(t_data *data);
void			close_all(t_data *data);

#endif
