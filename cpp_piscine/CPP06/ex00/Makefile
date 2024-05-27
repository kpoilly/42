# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 18:29:47 by kpoilly           #+#    #+#              #
#    Updated: 2024/05/27 14:06:09 by kpoilly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= Scalar
FILES 			= main.cpp ScalarConverter.cpp
HEAD			= ScalarConverter.hpp
SRCS 			= $(addprefix ./objs/, $(FILES))
OBJECTS 		= $(SRCS:%.cpp=%.o)
RM 						= rm -f
CC 						= c++
CFLAGS 			= -Wall -Wextra -Werror -MMD

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