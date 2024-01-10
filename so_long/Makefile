# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 15:44:44 by kpoilly           #+#    #+#              #
#    Updated: 2024/01/10 11:12:28 by kpoilly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= so_long
HEAD			= ./data/headers/so_long.h ./data/headers/so_long_struct.h

BUILD_DIR		= ./data/objects

CONST_FILES 	= utils.c get_map.c check_error.c load_images.c load_walls.c \
				  tile_transparency.c move_tab.c free.c check_path.c
CONST_OBJ 		= $(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/, $(CONST_FILES)))

MANDATORY 		= so_long.c events.c end_game.c render_map.c set_up.c
MANDATORY_OBJ 	= $(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/, $(MANDATORY)))

BONUS_BUILD_DIR	= ./bonus/objects
BONUS_FILES		= enemy.c enemy_directions.c enemy_utils.c enemy_move.c \
				  anim_setup.c so_long_bonus.c events_bonus.c end_game_bonus.c \
				  render_map_bonus.c set_up_bonus.c anim_load.c free_bonus.c enemy_load.c
BONUS_OBJ 		= $(patsubst %.c, %.o, $(addprefix $(BONUS_BUILD_DIR)/, $(BONUS_FILES)))

GNL_FILES 		= ./data/GNL/get_next_line.c ./data/GNL/get_next_line_utils.c
GNL_OBJECTS 	= $(GNL_FILES:.c=.o)

PRINTF_FILES	= ./data/ft_printf/ft_printf.c ./data/ft_printf/ft_printnbr.c \
				  ./data/ft_printf/ft_printstr.c ./data/ft_printf/ft_utils.c
PRINTF_OBJECTS 	= $(PRINTF_FILES:.c=.o)

RM 			= rm -f
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror -g3

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
				@$(CC) $(CFLAGS) -I ./data/headers -o $(NAME) $(CONST_OBJ) $(MANDATORY_OBJ) $(GNL_OBJECTS) $(PRINTF_OBJECTS) \
				-L./data/minilibx-linux -lmlx_Linux -lX11 -lXext
				@echo "\033c\033[0;32mMandatory part compiled ✔️\033[0;37m"
				@echo "\033[0;32mStart the game with \033[0;3m./so_long map_path\033[0;32m, have fun!\033[0;3m"

bonus:			fclean $(CONST_OBJ) $(BONUS_OBJ) $(GNL_OBJECTS) $(PRINTF_OBJECTS) $(HEAD)
						@$(CC) $(CFLAGS) -I ./data/headers -o $(NAME) $(CONST_OBJ) $(BONUS_OBJ) $(GNL_OBJECTS) $(PRINTF_OBJECTS) \
						-L./data/minilibx-linux -lmlx_Linux -lX11 -lXext
				@echo "\033c\033[0;32mBonus part compiled ✔️\033[0;37m"
				@echo "\033[0;32mStart the game with \033[0;3m./so_long map_path\033[0;32m, have fun!\033[0;37m"
										
clean:
						@$(RM) $(CONST_OBJ) $(MANDATORY_OBJ) $(BONUS_OBJ) $(GNL_OBJECTS) $(PRINTF_OBJECTS)
						@echo "\033[0;33m🧹Cleaned🧹\033[0;37m"

fclean:			clean
						@$(RM) $(NAME)

re:				fclean all

.PHONY:			all bonus clean fclean re