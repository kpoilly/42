# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 11:35:01 by jdoukhan          #+#    #+#              #
#    Updated: 2024/02/02 15:25:15 by kpoilly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libminilibft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./

NO_PSRCS = ft_printf.c ft_nbase.c ft_ptr.c gnl.c gnl_utils.c \
	ft_lstnew_bonus.c \
	ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
	ft_lstmap_bonus.c ft_lstsize_bonus.c ft_striteri.c ft_itoa.c ft_putchar_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c	ft_putstr_fd.c ft_split.c ft_strjoin.c ft_strmapi.c \
	ft_strtrim.c ft_substr.c ft_calloc.c ft_strdup.c ft_atoi.c ft_bzero.c \
	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strnstr.c ft_strrchr.c ft_tolower.c \
	ft_toupper.c ft_strncmp.c ft_strnjoin.c ft_strndup.c
SOURCES =  $(addprefix srcs/, $(NO_PSRCS))

OBJECTS = $(SOURCES:srcs/%.c=objs/%.o)

all: $(NAME)
	@sleep 0

objs/%.o:srcs/%.c 
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJECTS)
	@ar -rcs $(NAME) $(OBJECTS)
	@echo "\033[0;33mMinilibft compiled ✔️\033[1;37m"

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[0;91mCleaned minilibft ✔️\033[1;37m"

re: fclean all

.PHONY: all clean fclean re
