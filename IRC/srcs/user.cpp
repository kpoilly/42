/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:31:27 by kpoilly           #+#    #+#             */
/*   Updated: 2024/12/11 16:59:16 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.hpp"

User::User(int fd): _clientfd(fd)
{
	std::stringstream str_fd;
	str_fd << fd;
	this->_name = "Client" + str_fd.str();
	this->_realname = "";
	this->_is_authenticated = false;

	//To be deleted
	std::cout << "Server accepted a new client:" << std::endl;
	std::cout << "fd: " << this->_clientfd << std::endl;
	//------
};

User::~User()
{
	this->_joined_channels.clear();
};

bool		User::is_authenticated()
{
	return this->_is_authenticated;
};

//Getters
std::string User::get_buffer()
{
	return this->_buffer;
};

std::string	User::get_name()
{
	return this->_name;
};

std::string	User::get_IP()
{
	return this->_ipAddress;
};

std::string	User::get_real()
{
	return this->_realname;
};

int		User::get_fd()
{
	return this->_clientfd;
};

std::vector<Channel*> User::get_joined()
{
	return this->_joined_channels;
};


//Setters
void		User::authenticate()
{
	this->_is_authenticated = true;
	std::cout << SERV << this->_name << " has been authenticated." << std::endl;
};
void User::set_buffer(std::string const & content)
{
	this->_buffer = content;
};

void User::set_name(std::string name)
{
	this->_name = name;
	std::cout << "\033[1;31m[SERV]\033[0m user name: " << name << std::endl;
};
void User::set_IP(std::string IP)
{
	this->_ipAddress = IP;
	std::cout << "\033[1;31m[SERV]\033[0m user IP: " << IP << std::endl;
};
void User::set_real(std::string real)
{
	this->_realname = real;
	std::cout << "\033[1;31m[SERV]\033[0m user realname: " << real << std::endl;
};
void User::set_fd(int fd)
{
	this->_clientfd = fd;
	std::cout << "\033[1;31m[SERV]\033[0m user fd: " << fd << std::endl;
};

void		User::join_channel(Channel& channel)
{
	this->_joined_channels.push_back(&channel);
};

void		User::leave_channel(Channel& channel)
{
	for (std::vector<Channel*>::iterator it = this->_joined_channels.begin(); it != this->_joined_channels.end();)
	{
		if ((*it)->get_name() == channel.get_name())
		{
			this->_joined_channels.erase(it);
			return;
		}
		it++;
	};
};