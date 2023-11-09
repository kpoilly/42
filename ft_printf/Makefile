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
FILES		= 
BONUSFILES	= 
OBJECTS		= ${FILES:.c=.o}
BONUSOBJ	= ${BONUSFILES:.c=.o}
AR			= ar rcs
RM			= rm -f
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c -I ./ $< -o ${<:.c=.o}

${NAME}:	${OBJECTS}
			${AR} ${NAME} ${OBJECTS}

bonus:		${BONUSOBJ}
			${AR} ${NAME} ${OBJECTS} ${BONUSOBJ}

clean:
			${RM} ${OBJECTS} ${BONUSOBJ}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all bonus clean fclean re
