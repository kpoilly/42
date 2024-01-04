/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:57:41 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/04 16:08:26 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../GNL/get_next_line.h"
# include "../ft_printf/ft_printf.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <fcntl.h>

//contient les data des pointeurs mlx
typedef struct s_mlx {
	void	*ptr;
	void	*win;
	int		width;
	int		height;
}				t_mlx;

//contient les paths vers les .xpm
typedef struct s_set {
	char	*wallin;
	char	*wallout_up;
	char	*wallout_down;
	char	*wallout_left;
	char	*wallout_right;
	char	*ground;
	char	*collectible;
	char	*exit;
	char	*player_front;
	char	*player_back;
	char	*player_right;
	char	*player_left;
}				t_set;

//contient les donnes d'une image
typedef struct s_img {
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_len;
	int				endian;
	int				w;
	int				h;
	struct s_img	*next;
}				t_img;

//contient les data des entitees (joueur et ennemi)
typedef struct s_ent {
	t_img	front;
	t_img	back;
	t_img	right;
	t_img	left;
	t_img	last_state;
	char	chara;
	int		x;
	int		y;
}				t_ent;

//contient toutes les data du jeu
typedef struct s_global {
	t_mlx	mlx;
	t_set	set_of_files;
	char	**map;
	int		moves;
	int		nbcollec;
	char	last_gobdir;
	t_ent	player;
	t_ent	enemy;
	t_ent	wallout;
	t_img	bg;
	t_img	wallin;
	t_img	ground;
	t_img	collec;
	t_img	exit;
	clock_t	last;
	clock_t	anim;
}				t_global;

//map setup and primary functions
char			**get_map(char *filename, int *nb_line, int *nb_col);
char			**check_error(char **map, t_global *global);

//images loading & data setup
int				set_global(t_global *global, int nb_col, int nb_line);
int				load_walls(t_global *global);
int				load_things(t_global *global);
int				load_things2(t_global *global);
int				load_character1(t_global *global);
int				load_character2(t_global *global);
int				load_walls_updown(t_global *global);
int				load_walls_leftright(t_global *global);
int				free_images(t_global *global);

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

//animations
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

//end game
void			check_end_game(t_global *global);
void			end_the_game(t_global *global);
void			game_over(t_global *global);

//utils
char			*ft_itoa(int n);
void			free_the_map(char **map);


#endif