# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 13:32:57 by kpoilly           #+#    #+#              #
#    Updated: 2024/05/20 06:36:45 by kpoilly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	docker compose -f ./srcs/docker-compose.yml up -d --build

down:
	docker compose -f ./srcs/docker-compose.yml down

re:
	docker compose -f ./srcs/docker-compose.yml up -d --build --force-recreate

clear:

.PHONY:
	all down re clear
