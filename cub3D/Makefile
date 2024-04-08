# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 08:50:49 by lleciak           #+#    #+#              #
#    Updated: 2024/04/05 07:25:51 by kpoilly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#####################################################################################
#####ARGUMENTS
NAME 			= cub3D
HEAD			= ./utils/headers/cub3D.h ./utils/headers/cub3D_struct.h

BUILD_DIR		= ./utils/objects

CONST_FILES 	= main.c draw_background.c utils.c get_map_data.c ft_split.c get_map_utils.c\
				  tile_transparency.c load_and_free.c check_error.c events.c utils2.c set_up.c\
				  minimap.c minimap_utils.c moves.c raycasting.c draw_3D.c draw_game.c
CONST_OBJ 		= $(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/, $(CONST_FILES)))

MANDATORY 		= 
MANDATORY_OBJ 	= $(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/, $(MANDATORY)))

BONUS_BUILD_DIR	= ./bonus/objects
BONUS_FILES		= 
BONUS_OBJ 		= $(patsubst %.c, %.o, $(addprefix $(BONUS_BUILD_DIR)/, $(BONUS_FILES)))

GNL_FILES 		= ./utils/GNL/get_next_line.c ./utils/GNL/get_next_line_utils.c
GNL_OBJECTS 	= $(GNL_FILES:.c=.o)

PRINTF_FILES	= ./utils/ft_printf/ft_printf.c ./utils/ft_printf/ft_putnbr.c \
				  ./utils/ft_printf/ft_char_str.c
PRINTF_OBJECTS 	= $(PRINTF_FILES:.c=.o)

RM 			= rm -f
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror -g3

#####################################################################################
#####RULES

all:			$(NAME)

.c.o:
				@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
				
$(BUILD_DIR)/%.o:%.c
				@mkdir -p $(BUILD_DIR)
				@$(CC) $(CFLAGS) -c $< -o $@
$(BONUS_BUILD_DIR)/%.o:./bonus/%.c
				@mkdir -p $(BONUS_BUILD_DIR)
				@$(CC) $(CFLAGS) -c $< -o $@
				
$(NAME):		$(CONST_OBJ) $(MANDATORY_OBJ) $(GNL_OBJECTS) $(PRINTF_OBJECTS) $(HEAD)
				@$(CC) $(CFLAGS) -I ./utils/headers -o $(NAME) $(CONST_OBJ) $(MANDATORY_OBJ) $(GNL_OBJECTS) $(PRINTF_OBJECTS) \
				-L./utils/minilibx-linux -lmlx_Linux -lX11 -lXext -lm
				@echo "\033c\033[0;32mMandatory part compiled 🛸\033[0;37m"
				@echo "\033[0;32mStart the game with \033[0;3m./cub3D map_of_your_choice.cub\033[0;32m, have fun!\033[0;3m"

bonus:			fclean $(CONST_OBJ) $(BONUS_OBJ) $(GNL_OBJECTS) $(PRINTF_OBJECTS) $(HEAD)
						@$(CC) $(CFLAGS) -I ./utils/headers -o $(NAME) $(CONST_OBJ) $(BONUS_OBJ) $(GNL_OBJECTS) $(PRINTF_OBJECTS) \
						-L./utils/minilibx-linux -lmlx_Linux -lX11 -lXext
				@echo "\033c\033[0;32mBonus part compiled 👽\033[0;37m"
				@echo "\033[0;32mStart the game with \033[0;3m./cub3D map_of_your_choice.cub\033[0;32m, have fun!\033[0;37m"
										
clean:
						@$(RM) $(CONST_OBJ) $(MANDATORY_OBJ) $(BONUS_OBJ) $(GNL_OBJECTS) $(PRINTF_OBJECTS)
						@echo "\033[0;33m🧽Cleaned🫧\033[0;37m"

fclean:			clean
						@$(RM) $(NAME)

re:				fclean all

.PHONY:			all bonus clean fclean re