/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micromap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:30:42 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/10 14:00:26 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/headers/cub3D.h"

void	draw_micromap(t_data *data)
{
	if (data->micro.hand.img)
		mlx_destroy_image(data->mlx.ptr, data->micro.hand.img);
	load_texture(data, &(data->micro.hand), "./utils/textures/TABLETTEV2.xpm");
	put_img_to_img(data->bg, data->micro.hand, (SC_W / 2) - 500,
		SC_H - 535);
}
