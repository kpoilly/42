# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 18:29:47 by kpoilly           #+#    #+#              #
#    Updated: 2024/06/13 11:05:11 by kpoilly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= Base
FILES 			= main.cpp Base.cpp
HEAD			= Base.hpp
SRCS 			= $(addprefix ./objs/, $(FILES))
OBJECTS 		= $(SRCS:%.cpp=%.o)
RM 						= rm -f
CC 						= c++
CFLAGS 			= -Wall -Wextra -Werror -MMD -std=c++98

all:			$(NAME)

.cpp.o:
				$(CC) $(CFLAGS) -c $< -o ${<:.cpp=.o}

./objs/%.o:%.cpp
				@mkdir -p ./objs
				@$(CC) $(CFLAGS) -c $< -o $@
				
$(NAME):		$(OBJECTS) $(HEAD)
				$(CC) $(CFLAGS) -I ./ -o $(NAME) $(OBJECTS)	
							
clean:
						$(RM) $(OBJECTS)				
fclean:			clean
						$(RM) $(NAME)
re:						fclean all
.PHONY:		all clean fclean re