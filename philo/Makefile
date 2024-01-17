# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 12:24:39 by kpoilly           #+#    #+#              #
#    Updated: 2024/01/17 08:52:08 by kpoilly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= philo
HEAD			= ./data/headers/philo.h

BUILD_DIR		= ./data/objects
CONST_FILES 	= philo.c utils.c philo_lst_setup.c actions.c check_error.c
CONST_OBJ 		= $(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/, $(CONST_FILES)))

MAND_FILES 		= 
MAND_OBJ 		= $(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/, $(MAND_FILES)))

BONUS_FILES 	= 
BONUS_OBJ 		= $(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/, $(BONUS_FILES)))

PRINTF_FILES	= ./data/ft_printf/ft_printf.c ./data/ft_printf/ft_printnbr.c \
				  ./data/ft_printf/ft_printstr.c ./data/ft_printf/ft_utils.c
PRINTF_OBJECTS 	= $(PRINTF_FILES:.c=.o)

RM 						= rm -f
CC 						= cc
CFLAGS 			= -Wall -Wextra -Werror -g3

all:			$(NAME)

.c.o:
				$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
$(BUILD_DIR)/%.o:%.c
				mkdir -p $(BUILD_DIR)
				$(CC) $(CFLAGS) -c $< -o $@
				
$(NAME):		$(CONST_OBJ) $(MAND_OBJ) $(PRINTF_OBJECTS) $(HEAD)
				$(CC) $(CFLAGS) -I ./data/headers -o $(NAME) $(CONST_OBJ) $(MAND_OBJ) $(PRINTF_OBJECTS)

bonus: 			fclean $(CONST_OBJ) $(BONUS_OBJ) $(PRINTF_OBJECTS) $(HEAD)
					$(CC) $(CFLAGS) -I ./data/headers -o $(NAME) $(CONST_OBJ) $(BONUS_OBJ) $(PRINTF_OBJECTS)
				
clean:
					$(RM) $(CONST_OBJ) $(MAND_OBJ) $(BONUS_OBJ)	$(PRINTF_OBJECTS)	
fclean:			clean
					$(RM) $(NAME)
re:				fclean all
.PHONY:		all clean fclean re bonus