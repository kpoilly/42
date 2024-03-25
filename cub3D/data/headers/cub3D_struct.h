/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 07:36:37 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/25 07:56:41 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

# include "./cub3D.h"

//contient les data des pointeurs mlx
typedef struct s_mlx {
	void	*ptr;
	void	*win;
	int		width;
	int		height;
}	t_mlx;

//contient les data du joueur
typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	int		rota;
}	t_player;

typedef struct s_data
{
	t_mlx	mlx;
	char	**map;
	int		pcoord_x;
	int		pcoord_y;
}	t_data;

#endif