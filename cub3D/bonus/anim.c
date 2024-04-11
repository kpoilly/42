/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:02:12 by lleciak           #+#    #+#             */
/*   Updated: 2024/04/11 10:47:14 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/cub3D.h"

//plus tard on pourait join path de la texture + 2, 3, 4...
//et access voir si le fichier existe comme ca pas besoin
//de faire a la main, tout sera auto en fonction du nb de fichiers
//et ce sera chouette cool
//et aussi faire un t_anim avec le pointeur vers debut de la lst
//et la size de la lst, plus facile pour free, un while qui parcours
//avec la size, parceque while(lst->next) marche pas ici vu que
//ce sont des lists circulaires
void	setup_img_anim(t_data *data)
{
	t_img	*tmp;

	data->anim_no = &data->no;
	tmp = malloc(sizeof(t_img));
	load_texture(data, tmp, "./utils/textures/NO2.xpm");
	data->anim_no->next = tmp;
	tmp->next = data->anim_no;

	t_img	*tmp1;
	t_img	*tmp2;

	data->anim_we = &data->we;
	tmp1 = malloc(sizeof(t_img));
	load_texture(data, tmp1, "./utils/textures/WE2.xpm");
	data->anim_we->next = tmp1;
	tmp2 = malloc(sizeof(t_img));
	load_texture(data, tmp2, "./utils/textures/WE3.xpm");
	tmp1->next = tmp2;
	tmp2->next = data->anim_we;

	t_img	*tmp3;
	t_img	*tmp4;
	t_img	*tmp5;
	t_img	*tmp6;

	data->anim_so = &data->so;
	tmp3 = malloc(sizeof(t_img));
	load_texture(data, tmp3, "./utils/textures/SO2.xpm");
	data->anim_so->next = tmp3;
	tmp4 = malloc(sizeof(t_img));
	load_texture(data, tmp4, "./utils/textures/SO3.xpm");
	tmp3->next = tmp4;
	tmp5 = malloc(sizeof(t_img));
	load_texture(data, tmp5, "./utils/textures/SO4.xpm");
	tmp4->next = tmp5;
	tmp6 = malloc(sizeof(t_img));
	load_texture(data, tmp6, "./utils/textures/SO5.xpm");
	tmp5->next = tmp6;
	tmp6->next = data->anim_so;
}

