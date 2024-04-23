/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micromap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:30:42 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/12 11:35:32 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/headers/cub3D.h"

//draw the whole micromap with every components
void	draw_micromap(t_data *data)
{
	put_img_to_img(data->bg, data->micro.hand, (SC_W / 2) - 500,
		SC_H - 535);
}
