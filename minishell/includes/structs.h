/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:57:46 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/16 16:57:01 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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
}	t_shell;

#endif
