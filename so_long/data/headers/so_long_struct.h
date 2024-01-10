/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:14:56 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/10 19:39:30 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCT_H
# define SO_LONG_STRUCT_H

# include "./so_long.h"

//contient les data des pointeurs mlx
typedef struct s_mlx {
	void	*ptr;
	void	*win;
	int		width;
	int		height;
}				t_mlx;

//contient les paths vers les .xpm
typedef struct s_set {
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
	struct s_img	*prev;
}				t_img;

//contient les paths vers les .xpm des anims
typedef struct s_setanim {
	char	*front2;
	char	*back2;
	char	*right2;
	char	*left2;
}				t_setanim;

//contient les data des entitees (joueur et ennemi)
typedef struct s_ent {
	t_img		front;
	t_img		front2;
	t_img	back;
	t_img		back2;
	t_img		right;
	t_img		right2;
	t_img		left;
	t_img		left2;
	t_img		last_state;
	t_setanim	paths;
	char		chara;
	char		last_dir;
	int			x;
	int			y;
}				t_ent;

//contient toutes les data du jeu
typedef struct s_global {
	t_mlx	mlx;
	t_set	set_of_files;
	char	**map;
	int		moves;
	int		nbcollec;
	t_ent	player;
	t_ent	enemy;
	t_ent	wallout;
	t_ent	wallin;
	t_img	bg;
	t_img	ground;
	t_img	collec;
	t_img	exit;
	clock_t	last;
	clock_t	anim;
}				t_global;

#endif