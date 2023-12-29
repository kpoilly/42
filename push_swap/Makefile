# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 12:24:39 by kpoilly           #+#    #+#              #
#    Updated: 2023/12/29 14:44:48 by kpoilly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= push_swap
FILES 			= push_swap.c push_swap_ops.c push_swap_utils.c rotate_ops.c \
				  stack_management.c stack_setup.c lst_management.c ext_functions.c
BUILD_DIR		=	./objects
OBJECTS 		= $(patsubst %.c, %.o, $(addprefix $(BUILD_DIR)/, $(FILES)))
RM 						= rm -f
CC 						= cc
CFLAGS 			= -Wall -Wextra -Werror -g3

all:			$(NAME)

.c.o:
				$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
$(BUILD_DIR)/%.o:%.c
				mkdir -p $(BUILD_DIR)
				$(CC) $(CFLAGS) -c $< -o $@
				
$(NAME):		$(OBJECTS)
				$(CC) $(CFLAGS) -I ./ -o $(NAME) $(OBJECTS)	
							
clean:
						$(RM) $(OBJECTS)				
fclean:			clean
						$(RM) $(NAME)
re:						fclean all
.PHONY:		all clean fclean re