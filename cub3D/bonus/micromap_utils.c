/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micromap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleciak <lleciak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:43:53 by lleciak           #+#    #+#             */
/*   Updated: 2024/04/10 15:54:04 by lleciak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/headers/cub3D.h"

void	draw_hand(t_data *data, t_img image, char *path)
{
	if (image.img)
		mlx_destroy_image(data->mlx.ptr, image.img);
	load_texture(data, &(image), path);
	put_img_to_img(data->bg, image, (SC_W / 2) - 500, SC_H - 535);
}
