# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 15:44:44 by kpoilly           #+#    #+#              #
#    Updated: 2023/12/18 13:42:58 by kpoilly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= so_long

FILES 			= so_long.c set_up.c utils.c get_map.c check_error.c \
				  load_images.c render_map.c events.c tile_transparency.c \
				  move_tab.c end_game.c
OBJECTS 		= $(FILES:.c=.o)

GNL_FILES 		= ./data/GNL/get_next_line.c ./data/GNL/get_next_line_utils.c
GNL_OBJECTS 	= $(GNL_FILES:.c=.o)

PRINTF_FILES	= ./data/ft_printf/ft_printf.c ./data/ft_printf/ft_printnbr.c \
				  ./data/ft_printf/ft_printstr.c ./data/ft_printf/ft_utils.c
PRINTF_OBJECTS 	= $(PRINTF_FILES:.c=.o)

RM 						= rm -f
CC 						= cc
CFLAGS 			= -Wall -Wextra -Werror -g3

all:			$(NAME)

.c.o:
				$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
				
$(NAME):		$(OBJECTS) $(GNL_OBJECTS) $(PRINTF_OBJECTS)
				$(CC) $(CFLAGS) -I ./data/headers -o $(NAME) $(OBJECTS)	$(GNL_OBJECTS) $(PRINTF_OBJECTS) \
				-L./data/minilibx-linux -lmlx_Linux -lX11 -lXext
							
clean:
						$(RM) $(OBJECTS) $(GNL_OBJECTS) $(PRINTF_OBJECTS)				
fclean:			clean
						$(RM) $(NAME)
re:						fclean all
.PHONY:		all clean fclean re