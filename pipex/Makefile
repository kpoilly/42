# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 12:24:39 by kpoilly           #+#    #+#              #
#    Updated: 2024/01/09 12:29:15 by kpoilly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= pipex
HEAD			= ./data/headers/pipex.h

BUILD_DIR		= ./objects
CONST_FILES 	= pipex_utils.c ft_split.c check_exec.c check_path.c
CONST_OBJ 		= $(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/, $(CONST_FILES)))

MAND_FILES 		= pipex.c
MAND_OBJ 		= $(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/, $(MAND_FILES)))

BONUS_FILES 	= pipex_bonus.c here_doc.c
BONUS_OBJ 		= $(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/, $(BONUS_FILES)))

GNL_FILES 		= ./data/GNL/get_next_line.c ./data/GNL/get_next_line_utils.c
GNL_OBJECTS 	= $(GNL_FILES:.c=.o)

RM 						= rm -f
CC 						= cc
CFLAGS 			= -Wall -Wextra -Werror -g3

all:			$(NAME)

.c.o:
				$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
$(BUILD_DIR)/%.o:%.c
				mkdir -p $(BUILD_DIR)
				$(CC) $(CFLAGS) -c $< -o $@
				
$(NAME):		$(CONST_OBJ) $(MAND_OBJ) $(GNL_OBJECTS) $(HEAD)
				$(CC) $(CFLAGS) -I ./data/headers -o $(NAME) $(CONST_OBJ) $(MAND_OBJ) $(GNL_OBJECTS)

bonus: 			fclean $(CONST_OBJ) $(BONUS_OBJ) $(GNL_OBJECTS) $(HEAD)
					$(CC) $(CFLAGS) -I ./data/headers -o $(NAME) $(CONST_OBJ) $(BONUS_OBJ) $(GNL_OBJECTS)
				
clean:
					$(RM) $(CONST_OBJ) $(MAND_OBJ) $(BONUS_OBJ) $(GNL_OBJECTS)				
fclean:			clean
					$(RM) $(NAME)
re:				fclean all
.PHONY:		all clean fclean re bonus