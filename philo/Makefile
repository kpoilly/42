# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 12:24:39 by kpoilly           #+#    #+#              #
#    Updated: 2024/01/25 18:23:32 by kpoilly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= philo
HEAD			= ./data/headers/philo.h ./data/headers/philo_struct.h

BUILD_DIR		= ./data/objects
MAND_FILES 		= philo.c utils.c philo_lst_setup.c actions.c check_error.c \
				  philo_setup.c
MAND_OBJ 		= $(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/, $(MAND_FILES)))

RM 						= rm -f
CC 						= cc
CFLAGS 			= -Wall -Wextra -Werror -g3

all:			$(NAME)

.c.o:
				$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
$(BUILD_DIR)/%.o:%.c
				mkdir -p $(BUILD_DIR)
				$(CC) $(CFLAGS) -c $< -o $@
				
$(NAME):		$(MAND_OBJ) $(HEAD)
				$(CC) $(CFLAGS) -I ./data/headers -o $(NAME) $(CONST_OBJ) $(MAND_OBJ)
				
clean:
					$(RM) $(MAND_OBJ)
fclean:			clean
					$(RM) $(NAME)
re:				fclean all
.PHONY:		all clean fclean re bonus