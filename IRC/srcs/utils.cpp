/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:29:34 by kpoilly           #+#    #+#             */
/*   Updated: 2024/12/11 15:58:53 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.hpp"

extern Server* glob_serv;

void	stoc(int client_fd, std::string msg)
{
	std::cout << "\033[1;32m[SENT->" << client_fd << "]\033[0m"<< msg;
	//check le fd du client dans la poll et son flag voir si ready
	send(client_fd, msg.c_str(), msg.size(), 0);
};

void	ft_quit(int signal)
{
	(void)signal;
	std::cout << "\033[1;31m[SERV]\033[0m Closing server..." << std::endl;
	glob_serv->~Server();
	exit(0);
};

void	manage_signals(void)
{
	struct sigaction sa;

	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = &ft_quit;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
};

std::string sttostr(size_t i)
{
	std::ostringstream ss;
    ss << i;
    return ss.str();	
};

size_t	strtost(std::string str)
{
	std::istringstream ss(str);
    size_t ret;
    ss >> ret;
    return ret;
};

