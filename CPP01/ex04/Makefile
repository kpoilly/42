# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 18:29:47 by kpoilly           #+#    #+#              #
#    Updated: 2024/05/02 13:57:39 by kpoilly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= replace
FILES 			= main.cpp
HEAD			= 
OBJECTS 		= $(FILES:.cpp=.o)
RM 						= rm -f
CC 						= c++
CFLAGS 			= -Wall -Wextra -Werror -std=c++98

all:			$(NAME)

.cpp.o:
				$(CC) $(CFLAGS) -c $< -o ${<:.cpp=.o}
				
$(NAME):		$(OBJECTS) $(HEAD)
				$(CC) $(CFLAGS) -I ./ -o $(NAME) $(OBJECTS)	
							
clean:
						$(RM) $(OBJECTS)				
fclean:			clean
						$(RM) $(NAME)
re:						fclean all
.PHONY:		all clean fclean re