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

NAME		= libft.a
FILES		= ft_calloc.c ft_itoa.c ft_split.c ft_strtrim.c ft_isascii.c ft_memmove.c ft_memcpy.c ft_putchar_fd.c ft_putstr_fd.c ft_strdup.c ft_strlcat.c ft_strmapi.c ft_strrchr.c ft_tolower.c	ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memchr.c ft_putendl_fd.c ft_strlcpy.c ft_strncmp.c ft_toupper.c ft_bzero.c ft_isalpha.c ft_isprint.c ft_memcmp.c ft_memset.c ft_putnbr_fd.c ft_strchr.c ft_strjoin.c ft_strlen.c ft_strnstr.c ft_substr.c
BONUSFILES	= ft_lstnew.c ft_lstsize.c ft_lstadd_front.c ft_lstlast.c
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
			${RM} ${OBJECTS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
