/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_irc.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:08:36 by kpoilly           #+#    #+#             */
/*   Updated: 2024/12/11 16:57:00 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IRC_HPP
# define FT_IRC_HPP

# include <iostream>
# include <sstream>
# include <exception>
# include <cstring>
# include <vector>
# include <sys/socket.h>
# include <sys/types.h>
# include <netinet/in.h>
# include <fcntl.h>
# include <unistd.h>
# include <arpa/inet.h>
# include <poll.h>
# include <csignal>
# include <cstdio>
# include <stdlib.h>
# include <signal.h>

# include "server.hpp"
# include "channel.hpp"
# include "user.hpp"
# include "Message.hpp"

# define DEFAULT_IRC_PORT	6667
# define MAX_CLIENTS_NB		5

# define SERV				"\033[1;31m[SERV]\033[0m"

//codes
# define RPL_VERSION		"1.0"
# define RPL_ISUPPORT		"005"
# define RPL_WHOISUSER		"311 "
# define RPL_WHOISCHANNELS	"319 "
# define RPL_ENDOFWHOIS		"318 "
# define RPL_CHANNELMODEIS	"324 "
# define RPL_UMODEIS		"221 "
# define RPL_NOTOPIC		"331 "
# define RPL_TOPIC			"332 "
# define RPL_NAMREPLY		"353 "
# define RPL_ENDOFNAMES		"366 "
# define RPL_WHOREPLY		"352 "
# define RPL_ENDOFWHO		"315 "
# define RPL_LIST			"322 "
# define RPL_LISTEND		"323 "
# define RPL_INVITING		"341 "

//errors
# define ERR_NEEDMOREPARAMS		"461 " 
# define ERR_NOTREGISTERED		"451 " 

# define ERR_NICKNAMEINUSE		"433 "
# define ERR_NONICKNAMEGIVEN	"431 "
# define ERR_NOSUCHNICK 		"401 "

# define ERR_NOSUCHCHANNEL		"403 "
# define ERR_BADCHANNELKEY		"475 "
# define ERR_INVITEONLYCHAN		"473 "
# define ERR_CHANNELISFULL		"471 "
# define ERR_USERNOTINCHANNEL	"441 " 
# define ERR_NOTONCHANNEL		"442 "
# define ERR_USERONCHANNEL		"443 "
# define ERR_CHANOPRIVSNEEDED	"482 "

# define ERR_NORECIPIENT		"411 "
# define ERR_NOTEXTTOSEND		"412 "
# define ERR_CANNOTSENDTOCHAN	"404 "

class Server;

void	parsing(Server& server, int client_fd, Message& input);

//utils
void		stoc(int client_fd, std::string msg);
void		manage_signals(void);
std::string sttostr(size_t i);
size_t		strtost(std::string str);


//commands
void	cap(Server& server, int client_fd, std::string arg);
void	pong(int client_fd, std::string arg);
void	version(int client_fd);
void	motd(Server &server, int client_fd);
void	user(Server& server, int client_fd, std::string name, std::string IP, std::string real);
void	nick(Server& server, int client_fd, std::string arg);
void	whois(Server &server, int client_fd, std::string arg);
void	pass(Server &server, int client_fd, std::string arg);
void	who(Server& server, int client_fd, std::string arg);
void	join(Server& server, int client_fd, std::string name, std::string password);
void	part(Server& server, int client_fd, std::string channel, std::string reason);
void	list(Server& server, int client_fd, std::string channel);
void	privmsg(Server& server, int client_fd, std::string args);
void	invite(Server& server, int client_fd, std::string target, std::string channel);
void	quit(Server& server, int client_fd, std::string arg);
void	topic(Server& server, int client_fd, std::string channelname, std::string args);
void	kick(Server& server, int client_fd, std::string channelname, std::string target, std::string args);
void	mode(Server& server, int client_fd, std::string channelname, std::string modes, Message& input);

#endif