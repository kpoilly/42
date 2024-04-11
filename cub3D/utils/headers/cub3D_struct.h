/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 07:36:37 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/11 16:17:24 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

# include "./cub3D.h"

# define SC_W 1280
# define SC_H 720
# define TILE_SIZE 64
# define FOV 66
# define ROT_SPEED 5
# define PLAY_SPEED 5

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_M 109
# define KEY_INT 47
# define KEY_ESC 65307

# define PI 3.1415926535
# define DEG 0.0174533

//contient les data des pointeurs mlxx
typedef struct s_mlx {
	void	*ptr;
	void	*win;
	int		width;
	int		height;
}	t_mlx;

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

//contient les data du joueur en pixel
typedef struct s_player
{
	float		x;
	float		y;
	float		a;
	float		dirx;
	float		diry;
	int			mapx;
	int			mapy;
}	t_player;

typedef struct s_minimap
{
	t_img	map;
	t_img	player;
	int		sq_size;
	int		w_color;
	int		g_color;
	int		p_color;
	float	x;
	float	y;
	int		w;
	int		h;
}	t_minimap;

typedef struct s_micromap
{
	t_img	map;
	t_img	hand;
	t_img	thumb;
	int		sq_size;
	int		w_color;
	int		g_color;
	int		p_color;
	float	x;
	float	y;
	int		w;
	int		h;
}	t_micromap;

typedef struct s_ray
{
	float	x;
	float	y;
	float	a;
	float	xo;
	float	yo;
	int		texx;
	int		texy;
	int		color;
	int		hit;
	int		side;
	int		mapx;
	float	wall_h;
	int		nb;
}	t_ray;

typedef struct s_wall_line
{
	t_img	line;
	float	h;
	int		w;
	int		color;
}	t_wall_line;


// coordonnee dans la map
typedef struct s_data
{
	t_mlx		mlx;
	char		**map;
	int			map_h;
	int			map_w;
	int			*floor_colors;
	int			*ceiling_colors;
	char		*no_text;
	char		*so_text;
	char		*we_text;
	char		*ea_text;
	int			forward;
	int			backward;
	int			left;
	int			right;
	int			r_right;
	int			r_left;
	int			open_map;
	int			open_mmap;
	int			time_no;
	int			time_so;
	t_img		*anim_no;
	t_img		*anim_so;
	t_img		*anim_we;
	t_img		bg;
	t_img		no;
	t_img		so;
	t_img		we;
	t_img		ea;
	t_ray		ray;
	t_player	player;
	t_minimap	mini;
	t_micromap	micro;
	t_wall_line	wine;
}	t_data;

#endif