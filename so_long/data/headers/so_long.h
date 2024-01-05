/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:57:41 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/05 14:35:35 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../GNL/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "./so_long_struct.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <fcntl.h>

//map setup and primary functions
char			**get_map(char *filename, int *nb_line, int *nb_col);
char			**check_error(char **map, t_global *global);
int				check_path(t_global *global);
char			**map_dup(char **map);
char			**flood_fill(char **map, int x, int y);
int				is_reachable(char **map);
void			free_the_map(char **map);

//images loading & data setup
int				set_global(t_global *global, int nb_col, int nb_line);
int				load_walls(t_global *global);
int				load_things(t_global *global);
int				load_things2(t_global *global);
int				load_character1(t_global *global);
int				load_character2(t_global *global);
int				load_walls_updown(t_global *global);
int				load_walls_leftright(t_global *global);
void			free_images(t_global *global);

//tile transparency
void			put_img_to_img(t_img dst, t_img src, int x, int y);

//map rendering
void			render_map(t_global *global, t_img state);
void			putnbr_mouvements(t_global *global);
void			putstr_endgame(t_global *global);

//events (keypress, idle events, kill process etc...)
int				keypress(int keycode, t_global *global);
int				no_event(t_global *global);
int				destroy(t_global *global);

//player mouvements in tab
void			move_tab_up(t_global *global);
void			move_tab_down(t_global *global);
void			move_tab_right(t_global *global);
void			move_tab_left(t_global *global);

//end game
void			check_end_game(t_global *global);
void			end_the_game(t_global *global);
void			game_over(t_global *global);

//utils
char			*ft_itoa(int n);
void			set_coord(t_global *global, t_ent *target);

//--- BONUS ---

//bonus management
void			free_bonus(t_global *global);

//animations
void			set_paths_anim(t_global *global);
int				load_anim(t_global *global);
void			set_next(t_global *global);

//enemy spawn and setup
void			spawn_enemy(t_global *global, int nb_line, int nb_col);

//enemy utils
void			set_lastdir(t_global *global, char dir);
void			set_coord(t_global *global, t_ent *target);
int				in_range(int player_x, int player_y, int x, int y);

//enemy mouvements
void			move_enemy(t_global *global);
void			enemy_decision(t_global *global);
void			move_enemy_tab(t_global *global, char *dest, char *src);
void			search_right(t_global *global, int x, int y);
void			search_left(t_global *global, int x, int y);
void			search_down(t_global *global, int x, int y);
void			search_up(t_global *global, int x, int y);
void			track_player(t_global *global, int x, int y);
void			patrol(t_global *global, int x, int y);

#endif