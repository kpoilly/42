/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoukhan <jdoukhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:50:32 by jdoukhan          #+#    #+#             */
/*   Updated: 2024/02/16 16:57:55 by jdoukhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "minilibft.h"
# include "structs.h"
# include "mini_funcs.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>

//signal handling
# include <poll.h>
# include <signal.h>
# include <bits/sigaction.h>

//readline func
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# define PROMPT_START "\x1B[38;5;37m["
# define PROMPT_END "]\x1B[0m "
# define HISTORY_FILE "/.minishell_history"
# define HISTORY_SIZE 15

# ifndef SA_RESTART
#  define SA_RESTART 0
# endif

#endif
