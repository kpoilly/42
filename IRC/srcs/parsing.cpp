/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:21:27 by kpoilly           #+#    #+#             */
/*   Updated: 2024/12/11 16:56:48 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.hpp"

void	parsing(Server& server, int client_fd, Message& input)
{
	std::cout << "\033[1;35m[RECV<-" << client_fd << "]\033[0m" << input.get_content() << std::endl;
	
	try
	{
		if (!server.get_user(client_fd).is_authenticated() && input.get_command() != "PASS" && input.get_command() != "CAP")
			stoc(client_fd, ERR_NOTREGISTERED + server.get_user(client_fd).get_name() + " " + input.get_command() + " :You are not registered.\r\n");
		else if (input.get_command() == "CAP")
			cap(server, client_fd, input.get_param(0));
		else if (input.get_command() == "NICK")
			nick(server, client_fd, input.get_param(0));
		else if (input.get_command() == "USER")
			user(server, client_fd, input.get_param(0), input.get_param(2), input.get_param(1));
		else if (input.get_command() == "PING")
			pong(client_fd, input.get_param(0));
		else if (input.get_command() == "VERSION")
			version(client_fd);
		else if (input.get_command() == "MOTD")
			motd(server, client_fd);
		else if (input.get_command() == "WHOIS")
			whois(server, client_fd, input.get_param(0));
		else if (input.get_command() == "PASS")
			pass(server, client_fd, input.get_param(0));
		else if (input.get_command() == "WHO")
			who(server, client_fd, input.get_param(0));
		else if (input.get_command() == "JOIN")
		{
			if (input.get_nbparam() == 2)
				join(server, client_fd, input.get_param(0), input.get_param(1));
			else
				join(server, client_fd, input.get_param(0), "");
		}
		else if (input.get_command() == "PART")
		{
			if (input.get_nbparam() == 2)
				part(server, client_fd, input.get_param(0), input.get_param(1));
			else
				part(server, client_fd, input.get_param(0), "");
		}
		else if (input.get_command() == "LIST")
			list(server, client_fd, input.get_param(0));
		else if (input.get_command() == "PRIVMSG")
			privmsg(server, client_fd, input.get_content());
		else if (input.get_command() == "INVITE")
			invite(server, client_fd, input.get_param(0), input.get_param(1));
		else if (input.get_command() == "QUIT")
			quit(server, client_fd, input.get_param(0));
		else if (input.get_command() == "TOPIC")
			topic(server, client_fd, input.get_param(0), input.get_content());
		else if (input.get_command() == "KICK")
			kick(server, client_fd, input.get_param(0), input.get_param(1), input.get_content());
		else if (input.get_command() == "MODE")
			mode(server, client_fd, input.get_param(0), input.get_param(1), input);
	}
	catch (Server::UserQuit)
	{
		throw;
	}
	catch (std::exception& e)
	{
		stoc(client_fd, ERR_NEEDMOREPARAMS + server.get_user(client_fd).get_name() + " " + input.get_command() +" :Not enough parameters given\r\n");
		return;
	}
};