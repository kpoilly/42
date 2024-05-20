# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 13:32:57 by kpoilly           #+#    #+#              #
#    Updated: 2024/05/15 13:52:26 by kpoilly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	sudo hostsed add 127.0.0.1 kpoilly.42.fr
	sudo docker compose -f ./srcs/docker-compose.yml up -d --build

down:
	sudo docker compose -f ./srcs/docker-compose.yml down

re:
	sudo hostsed add 127.0.0.1 kpoilly.42.fr
	sudo docker compose -f ./srcs/docker-compose.yml up -d --build --force-recreate

clean:
	sudo hostsed remove 127.0.0.1 kpoilly.42.fr
	sudo docker system prune -af

.PHONY:
	all down re clear
