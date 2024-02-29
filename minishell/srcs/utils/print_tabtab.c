/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tabtab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:38:37 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/13 13:45:03 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_tabtab(char ***tabtab)
{
	int	i;
	int	j;

	i = 0;
	while (tabtab && tabtab[i])
	{
		j = 0;
		while (tabtab[i] && tabtab[i][j])
		{
			printf("%s_", tabtab[i][j]);
			j++;
		}
		printf("| \n");
		i++;
	}
	printf("\n");
}
