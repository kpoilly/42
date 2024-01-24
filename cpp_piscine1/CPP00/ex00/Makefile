# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 09:11:08 by kpoilly           #+#    #+#              #
#    Updated: 2024/01/23 09:11:09 by kpoilly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= megaphone
FILES 			= megaphone.cpp
OBJECTS 		= $(FILES:.cpp=.o)
RM 						= rm -f
CC 						= c++
CFLAGS 			= -Wall -Wextra -Werror

all:			$(NAME)

.c.o:
				$(CC) $(CFLAGS) -c $< -o ${<:.cpp=.o}
				
$(NAME):		$(OBJECTS)
				$(CC) $(CFLAGS) -I ./ -o $(NAME) $(OBJECTS)	
							
clean:
						$(RM) $(OBJECTS)				
fclean:			clean
						$(RM) $(NAME)
re:						fclean all
.PHONY:		all clean fclean re