/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:20:15 by kpoilly           #+#    #+#             */
/*   Updated: 2024/12/11 15:02:12 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include "ft_irc.hpp"

class Channel;
class User;

class Server
{
	private:
		int						_fd;
		int						_port;
		int						_socket_options;
		sockaddr_in 			_address;
		std::string				_ip;
		std::string				_password;
		std::string				_motd;
		
		std::vector<Channel*> 	_channels_list;
		std::vector<User*> 		_users_list;

		std::vector<pollfd>		_pollfd;

	public:
		//Setup
		Server(int port, std::string const &password = NULL);
		~Server();
	
		//Getters
		int						get_servfd();
		std::string				get_ip();
		int						get_port() const;
		std::string				get_password();
		std::vector<Channel*>	get_channels_list();
		std::vector<User*>		get_users_list();
		User&					get_user(int fd);
		User&					get_user(std::string name);
		Channel&				get_channel(std::string name);
		std::string				get_motd();
		pollfd&					get_pollfd(int fd);
		std::vector<pollfd>		get_pollfd_list() const;

		//Utils
		void	loop();
		int		open_poll();
		void	handle_poll(pollfd it);
		void	communicate(User & user);
		std::vector<pollfd>::iterator	user_quit(std::vector<pollfd>::iterator & it);

		void	add_channel(std::string name, std::string password);
		void	remove_channel(std::string name);
		bool	channel_exists(std::string name);
		void	add_user(User *user);
		void	remove_user(int fd);
		bool	check_nick(std::string name, int client_fd);
		bool	nick_exists(std::string name);

		void	send_to_all(std::string arg);
		void	disconnectServer();

		//Exceptions
		class UserQuit : public std::exception {};

		// void	print_channels();
		// void	print_users();
};

#endif