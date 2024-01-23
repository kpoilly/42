/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:18:03 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/23 10:26:59 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data/headers/so_long.h"

int	load_exit_anim(char *nb, t_global *global)
{
	char	*path;
	char	*tmp;

	path = ft_strjoin("./data/textures/exit0", nb);
	tmp = ft_strdup(path);
	free(path);
	path = ft_strjoin(tmp, ".xpm");
	free(tmp);
	mlx_destroy_image(global->mlx.ptr, global->exit.img);
	global->exit.img = mlx_xpm_file_to_image(global->mlx.ptr,
			path, &global->exit.w, &global->exit.h);
	if (!global->exit.img)
		return (ft_printf("Error.\nMissing texture files.\n"), 0);
	global->exit.addr = mlx_get_data_addr(global->exit.img,
			&global->exit.bits_per_pixel, &global->exit.line_len,
			&global->exit.endian);
	free(path);
	return (1);
}

void	exit_anim(t_global *global)
{
	int	i;
	int	timer;
	int	wait;

	i = 9;
	wait = 0;
	while (i >= -1)
	{
		timer = ((long double)(clock() - global->anim) / CLOCKS_PER_SEC) * 1000;
		if (timer >= wait && i >= 0)
		{
			global->anim = clock();
			if (!load_exit_anim(ft_itoa(i), global))
				return ((void)destroy(global));
			putimg_blackscreen(global, global->exit);
			i--;
		}
		if (i == -1 && timer >= wait * 10)
			i--;
		wait = 300;
	}
}
