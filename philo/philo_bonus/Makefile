# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 12:24:39 by kpoilly           #+#    #+#              #
#    Updated: 2024/01/25 18:22:55 by kpoilly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= philo_bonus
HEAD			= ./headers/philo_bonus.h ./headers/philo_struct_bonus.h

BUILD_DIR		= ./objects
FILES 	= philo_bonus.c utils_bonus.c philo_lst_setup_bonus.c actions_bonus.c\
				  check_error_bonus.c philo_setup_bonus.c
OBJ 		= $(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/, $(FILES)))

RM 						= rm -f
CC 						= cc
CFLAGS 			= -Wall -Wextra -Werror -g3

all:			$(NAME)

.c.o:
				$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
$(BUILD_DIR)/%.o:%.c
				mkdir -p $(BUILD_DIR)
				$(CC) $(CFLAGS) -c $< -o $@
				
$(NAME):		$(OBJ) $(HEAD)
				$(CC) $(CFLAGS) -I ./data/headers -o $(NAME) $(OBJ)
				
clean:
					$(RM) $(OBJ)
fclean:			clean
					$(RM) $(NAME)
re:				fclean all
.PHONY:		all clean fclean re bonus