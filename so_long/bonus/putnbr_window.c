/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:58:39 by kpoilly           #+#    #+#             */
/*   Updated: 2024/01/24 13:14:01 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../data/headers/so_long.h"

int	load_number(t_global *global, int nb)
{
	char	*path;
	char	*tmp;
	int		h;
	int		w;
	char	*nbr;

	h = 21;
	w = 20;
	nbr = ft_itoa(nb);
	path = ft_strjoin("./data/textures/numbers/", nbr);
	free(nbr);
	tmp = ft_strdup(path);
	free(path);
	path = ft_strjoin(tmp, ".xpm");
	free(tmp);
	global->numbers[nb].h = h;
	global->numbers[nb].w = w;
	global->numbers[nb].img = mlx_xpm_file_to_image(global->mlx.ptr,
			path, &global->numbers[nb].w, &global->numbers[nb].h);
	if (!global->numbers[nb].img)
		return (ft_printf("Error.\nMissing texture files.\n"), 0);
	global->numbers[nb].addr = mlx_get_data_addr(global->numbers[nb].img,
			&global->numbers[nb].bits_per_pixel, &global->numbers[nb].line_len,
			&global->numbers[nb].endian);
	return (free(path), 1);
}

int	numbers_setup(t_global *global)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (i < 10)
		check += load_number(global, i++);
	if (check != 10)
		return (0);
	return (1);
}

void	putnbr_window(t_global *global, int n, int x, int y)
{
	long	nb;

	nb = n;
	if (nb > 9)
	{
		putnbr_window(global, n / 10, x - 21, y);
		putnbr_window(global, n % 10, x, y);
	}
	else
		put_img_to_img(global->bg, global->numbers[nb], x, y);
}
