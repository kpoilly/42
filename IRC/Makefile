# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aautin <aautin@student.42.fr >             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 13:43:51 by kpoilly           #+#    #+#              #
#    Updated: 2024/12/07 19:25:48 by aautin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= ircserv

HEAD			= includes

M_FILES 		= Message.cpp main.cpp utils.cpp server.cpp channel.cpp user.cpp parsing.cpp \
				  commands.cpp
M_SRCS			= $(addprefix ./objs/, $(M_FILES))
M_OBJECTS 		= $(M_SRCS:%.cpp=%.o)

B_FILES 		= 
B_SRCS			= $(addprefix ./objs/bonus/, $(B_FILES))
B_OBJECTS 		= $(B_SRCS:%.cpp=%.o)

RM 				= @rm -f
CC 				= c++
CFLAGS 			= -Wall -Wextra -Werror -MMD -std=c++98 -g3

all:			$(NAME)

.cpp.o:
				@$(CC) $(CFLAGS) -I$(HEAD) -c $< -o ${<:.cpp=.o}

./objs/%.o:./srcs/%.cpp
				@mkdir -p ./objs
				@$(CC) $(CFLAGS) -I$(HEAD) -c $< -o $@
				
$(NAME):		$(M_OBJECTS) $(B_OBJECTS) $(HEAD)
				@$(CC) $(CFLAGS) -I$(HEAD) -o $(NAME) $(M_OBJECTS) $(B_OBJECTS)
				@echo "\033c\033[0;32mMandatory part compiled.\033[0;37m"

bonus:			fclean $(M_OBJECTS) $(B_OBJECTS) $(HEAD)
						@$(CC) $(CFLAGS) -I$(HEAD) -o $(NAME) $(M_OBJECTS) $(B_OBJECTS) \
				@echo "\033c\033[0;32mBonus part compiled.\033[0;37m"
							
clean:
						$(RM) $(M_OBJECTS) $(B_OBJECTS)
						@echo "\033[0;33m🧽Cleaned🫧\033[0;37m"

fclean:			clean
						$(RM) -r ./objs
						$(RM) $(NAME)
re:						fclean all
.PHONY:		all clean fclean re