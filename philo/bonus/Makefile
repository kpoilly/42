# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 12:24:39 by kpoilly           #+#    #+#              #
#    Updated: 2024/01/23 10:48:50 by kpoilly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= philo_bonus
HEAD			= ./headers/philo_bonus.h ./headers/philo_struct_bonus.h

BUILD_DIR		= ./objects_bonus
CONST_FILES 	= philo.c utils.c philo_lst_setup.c actions.c check_error.c \
				  philo_setup.c
CONST_OBJ 		= $(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/, $(CONST_FILES)))

MAND_FILES 		= 
MAND_OBJ 		= $(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/, $(MAND_FILES)))

BONUS_FILES 	= 
BONUS_OBJ 		= $(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/, $(BONUS_FILES)))

RM 						= rm -f
CC 						= cc
CFLAGS 			= -Wall -Wextra -Werror -g3

all:			$(NAME)

.c.o:
				$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
$(BUILD_DIR)/%.o:%.c
				mkdir -p $(BUILD_DIR)
				$(CC) $(CFLAGS) -c $< -o $@
				
$(NAME):		$(CONST_OBJ) $(MAND_OBJ) $(HEAD)
				$(CC) $(CFLAGS) -I ./data/headers -o $(NAME) $(CONST_OBJ) $(MAND_OBJ)

bonus: 			fclean $(CONST_OBJ) $(BONUS_OBJ) $(HEAD)
					$(CC) $(CFLAGS) -I ./data/headers -o $(NAME) $(CONST_OBJ) $(BONUS_OBJ)
				
clean:
					$(RM) $(CONST_OBJ) $(MAND_OBJ) $(BONUS_OBJ)
fclean:			clean
					$(RM) $(NAME)
re:				fclean all
.PHONY:		all clean fclean re bonus