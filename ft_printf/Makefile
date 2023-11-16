# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 12:47:33 by marvin            #+#    #+#              #
#    Updated: 2023/09/18 12:47:33 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
FILES		= ft_printf.c ft_printstr.c ft_printnbr.c ft_utils.c
OBJECTS		= ${FILES:.c=.o}
AR			= ar rcs
RM			= rm -f
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c -I ./ $< -o ${<:.c=.o}

${NAME}:	${OBJECTS}
			${AR} ${NAME} ${OBJECTS}

clean:
			${RM} ${OBJECTS} ${BONUSOBJ}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
