# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 08:50:49 by lleciak           #+#    #+#              #
#    Updated: 2024/04/24 10:41:04 by kpoilly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#####################################################################################
#####ARGUMENTS
NAME 			= cub3D
HEAD			= ./utils/headers/cub3D.h ./utils/headers/cub3D_struct.h

BUILD_DIR		= ./utils/objects

CONST_FILES 	= draw_background.c utils.c get_map_data.c ft_split.c tile_transparency.c\
                  raycast_utils.c
CONST_OBJ 		= $(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/, $(CONST_FILES)))

MANDATORY 		= main.c moves.c events.c micromap.c set_up.c draw_3D.c load_and_free.c\
				  check_error.c raycasting.c get_map_utils.c
MANDATORY_OBJ 	= $(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/, $(MANDATORY)))

BONUS_BUILD_DIR	= ./bonus/objects
BONUS_FILES		= main_bonus.c micromap_bonus.c events_bonus.c events_utils.c\
				  anim.c set_up_bonus.c draw_3D_bonus.c load_and_free_bonus.c  get_map_utils_bonus.c\
				  check_error_bonus.c minimap.c minimap_utils.c doors.c draw_obj.c raycasting_bonus.c\
				  draw_door.c micromap_utils.c utils_bonus.c doors_utils.c moves_bonus.c
BONUS_OBJ 		= $(patsubst %.c, %.o, $(addprefix $(BONUS_BUILD_DIR)/, $(BONUS_FILES)))

GNL_FILES 		= ./utils/GNL/get_next_line.c ./utils/GNL/get_next_line_utils.c
GNL_OBJECTS 	= $(GNL_FILES:.c=.o)

PRINTF_FILES	= ./utils/ft_printf/ft_printf.c ./utils/ft_printf/ft_putnbr.c \
				  ./utils/ft_printf/ft_char_str.c
PRINTF_OBJECTS 	= $(PRINTF_FILES:.c=.o)

RM 			= rm -f
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror -g3 -o3

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
						-L./utils/minilibx-linux -lmlx_Linux -lX11 -lXext -lm
				@echo "\033c\033[0;32mBonus part compiled 👽\033[0;37m"
				@echo "\033[0;32mStart the game with \033[0;3m./cub3D map_of_your_choice.cub\033[0;32m, have fun!\033[0;37m"
										
clean:
						@$(RM) $(CONST_OBJ) $(MANDATORY_OBJ) $(BONUS_OBJ) $(GNL_OBJECTS) $(PRINTF_OBJECTS)
						@echo "\033[0;33m🧽Cleaned🫧\033[0;37m"

fclean:			clean
						@$(RM) $(NAME)

re:				fclean all

.PHONY:			all bonus clean fclean re
