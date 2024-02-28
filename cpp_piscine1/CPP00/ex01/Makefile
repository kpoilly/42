# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 18:29:47 by kpoilly           #+#    #+#              #
#    Updated: 2023/12/11 18:31:28 by kpoilly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= phonebook
FILES 			= my_awesome_phonebook.cpp Contact.cpp PhoneBook.cpp
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