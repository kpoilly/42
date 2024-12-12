/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:49:34 by kpoilly           #+#    #+#             */
/*   Updated: 2024/12/10 21:02:26 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.hpp"

Server* glob_serv = NULL;

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cerr << "\033[1;31mircserv: invalid arguments.\n\033[3;30mcorrect format is ./ircserv <port> <password>\033[0m" << std::endl;
		return EXIT_SUCCESS;
	}

	int port = atoi(av[1]); //default irc port: 6667
	if(port < 0)
	{
		std::cerr << "\033[1;31mPort must be strictly positive\033[0m" << std::endl;
		return EXIT_SUCCESS;
	}
	
	try {
		manage_signals();
		Server server(port, av[2]);
		glob_serv = &server;
		server.loop();

	} catch (std::exception)
	{
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
};
