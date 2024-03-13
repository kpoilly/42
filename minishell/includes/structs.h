/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:57:46 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/03/12 15:05:35 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>

typedef struct s_hist
{
	char			*line;
	struct s_hist	*n;
}	t_hist;

typedef struct s_shell
{
	int		openf;
	char	*prompt;
	char	***input;
	char	**envp;
	t_hist	*h;
	int		bi_ret;
	char	*hist_path;
	bool	colors;
	int		int_save;
}	t_shell;

#endif
