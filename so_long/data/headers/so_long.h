/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:57:41 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/27 14:27:10 by kpoilly          ###   ########.fr       */
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

//contient les paths vers le .xpm
typedef struct s_set {
	char	*wallin;
	char	*wallout;
	char	*ground;
	char	*collectible;
	char	*exit;
	char	*player_face;
	char	*player_dos;
	char	*player_droit;
	char	*player_gauche;
}				t_set;

//contient les images chargees dans des buffers
typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}				t_img;

//contient toutes les data
typedef struct s_global {
	t_mlx	mlx;
	t_set	set_of_files;
	char	**map;
	int		moves;
	int		nbcollec;
	t_img	bg;
	t_img	wallin;
	t_img	wallout;
	t_img	ground;
	t_img	collec;
	t_img	exit;
	t_img	ennemy;
	t_img	player_face;
	t_img	player_dos;
	t_img	player_droit;
	t_img	player_gauche;
}				t_global;

//map setup and primary functions
char			**get_map(char *filename, int *nb_line, int *nb_col);
char			**check_error(char **map, t_global *global);

//images & data setup
int				set_global(t_global *global, int nb_col, int nb_line);
void			load_walls(t_global *global);
void			load_things(t_global *global);
void			load_things2(t_global *global);
void			load_character1(t_global *global);
void			load_character2(t_global *global);
int				free_images(t_global *global);

//tile transparency
void			put_img_to_img(t_img dst, t_img src, int x, int y);

//map render
void			render_map(t_global *global, t_img state);
void			putnbr_mouvements(t_global *global);

//events
int				keypress(int keycode, t_global *global);
int				no_event(void);
int				destroy(int keycode, t_global *global);

//perso moves
void			move_tab_up(t_global *global);
void			move_tab_down(t_global *global);
void			move_tab_right(t_global *global);
void			move_tab_left(t_global *global);

//ennemy
void			spawn_ennemy(t_global *global, int nb_line, int nb_col);

//end game
void			check_end_game(t_global *global);
void			end_the_game(t_global *global);

//utils
char			*ft_itoa(int n);

#endif