# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 10:51:15 by jdoukhan          #+#    #+#              #
#    Updated: 2024/02/02 15:13:05 by kpoilly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
BONUS_SOURCES = ft_lstnew_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c\
	ft_lstclear_bonus.c	ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c\
	ft_lstmap_bonus.c ft_lstsize_bonus.c 
SOURCES = ft_striteri.c ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
	ft_putstr_fd.c ft_split.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c\
	ft_calloc.c ft_strdup.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c\
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
	ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
	ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strncmp.c ft_strndup.c
OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

all: $(NAME)

.c.o: 
	@$(CC) $(CFLAGS) -c -I ./ $< -o ${<:.c=.o}

$(NAME) : $(OBJECTS)
	@ar -rcs $(NAME) $(OBJECTS)

bonus: all $(BONUS_OBJECTS)
	@ar -rcs $(NAME) $(OBJECTS) $(BONUS_OBJECTS)
	
clean:
	@rm -rf $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

#so: bonus
#	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SOURCES) $(BONUS_SOURCES)
#	gcc -nostartfiles -shared -o libft.so $(OBJECTS) $(BONUS_OBJECTS)

.PHONY: all clean fclean re bonus 
