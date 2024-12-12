/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:17:14 by kpoilly           #+#    #+#             */
/*   Updated: 2024/12/11 16:16:10 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.hpp"

Channel::Channel(std::string name): _name(name), _topic(""), _password(""), _inv_only(false), _restr_topic(true), _limit(0)
{};
Channel::Channel(const Channel& copy){*this = copy;};

Channel& Channel::operator=(const Channel& copy)
{
	this->_name = copy._name;
	this->_topic = copy._topic;
	this->_password = copy._password;
	this->_inv_only = copy._inv_only;
	this->_restr_topic = copy._restr_topic;
	this->_limit = copy._limit;
	//copier les vector.
	return *this;
};

Channel::~Channel()
{
	this->_invited_users.clear();
	this->connected_users.clear();
	this->_op_users.clear();
};

void	Channel::_add_user(User& user)
{
	this->connected_users.push_back(&user);	
};

void	Channel::_remove_user(User& user)
{
	for (std::vector<User*>::iterator it = this->connected_users.begin(); it != this->connected_users.end();)
	{
		if ((**it).get_name() == user.get_name())
		{
			this->connected_users.erase(it);
			return;
		}
		it++;
	};

	if (this->is_op(user))
		this->_remove_op(user);
};

void	Channel::set_limit(size_t lim)
{
	this->_limit = lim;
	std::cout << SERV << "limit for " << this->_name << " is now " << lim << std::endl;
};

void	Channel::add_invited(std::string username)
{
	this->_invited_users.push_back(username);	
};

void	Channel::remove_invited(std::string username)
{
	for (std::vector<std::string>::iterator it = this->_invited_users.begin(); it != this->_invited_users.end();)
	{
		if (*it == username)
		{
			this->_invited_users.erase(it);
			return;
		}
		it++;
	};
};

void	Channel::_add_op(User& user)
{
	this->_op_users.push_back(&user);
};

void	Channel::_remove_op(User& user)
{
	for (std::vector<User*>::iterator it = this->_op_users.begin(); it != this->_op_users.end();)
	{
		if ((**it).get_name() == user.get_name())
		{
			this->_op_users.erase(it);
			return;
		}
		it++;
	};
};

std::string	Channel::get_name()
{
	return this->_name;	
};

std::string	Channel::get_topic()
{
	return this->_topic;	
};

std::string	Channel::get_nb_users_str()
{
	std::stringstream nb_users;
	nb_users << this->connected_users.size();
	return nb_users.str();
};

void Channel::set_password(std::string password)
{
	std::cout << SERV << "password for " << this->_name << " is now set to: " << password << std::endl;
	this->_password = password;
};

bool	Channel::is_op(User& user)
{
	for (std::vector<User*>::iterator it = this->_op_users.begin(); it != this->_op_users.end();)
	{
		if ((**it).get_name() == user.get_name())
			return true;
		it++;
	};
	return false;
};

bool	Channel::is_connected(User& user)
{
	for (std::vector<User*>::iterator it = this->connected_users.begin(); it != this->connected_users.end();)
	{
		if ((**it).get_name() == user.get_name())
			return true;
		it++;
	};
	return false;
};

bool	Channel::is_invited(User& user)
{
	for (std::vector<std::string>::iterator it = this->_invited_users.begin(); it != this->_invited_users.end();)
	{
		if (*it == user.get_name())
			return true;
		it++;
	};
	return false;
};

bool			Channel::is_topic_restr()
{
	return this->_restr_topic;
};

bool			Channel::is_passworded()
{
	return !(this->_password.empty());
};

bool			Channel::is_invite_only()
{
	return this->_inv_only;
};

bool			Channel::is_cap_limited()
{
	return !(this->_limit == 0);
};

void	Channel::join(User &user, std::string password)
{
		//check si channel en inv only et user invited
		if (this->_inv_only && !this->is_invited(user))
		{
			stoc(user.get_fd(), ERR_INVITEONLYCHAN + user.get_name() + " " + this->get_name() + " :Invite Only (+i).\r\n");
			return;
		}
			
		//check si channel est limited et si limite pas atteinte
		if (this->_limit != 0 && this->connected_users.size() >= this->_limit)
		{
			stoc(user.get_fd(), ERR_CHANNELISFULL + user.get_name() + " " + this->get_name() + " :Channel is full (+l).\r\n");
			return;
		}
			
		//Check if password needed or not (if yes, is the right password given)
		if(this->_password.empty() || password == this->_password)
		{
			user.join_channel(*this);
			if (this->connected_users.size() == 0)
				this->_add_op(user);
			this->_add_user(user);
			this->send_connected_users(user);
			stoc(user.get_fd(), ":" + user.get_name() + "!" + user.get_real() + "@" + user.get_IP() + " JOIN " + this->_name + "\r\n");
			std::cout << SERV << user.get_name() << " joined " << this->_name << std::endl;
			if (is_invited(user))
				this->remove_invited(user.get_name());
			return;
		}
		else
		{
			stoc(user.get_fd(), ERR_BADCHANNELKEY + user.get_name() + " " + this->get_name() + " :Password mismatch (+k).\r\n");
			return;
		}
};

void	Channel::part(User &user, std::string msg)
{
	this->send_to_all(":" + user.get_name() + "!" + user.get_real() + "@" + user.get_IP() + " PART " + this->_name + " :" + msg + "\r\n");
	this->_remove_user(user);
	if (this->is_op(user))
		this->_remove_op(user);
};

void	Channel::send_connected_users(User& user)
{
	std::string tosend = RPL_NAMREPLY + user.get_name() + "!" + user.get_real() + "@" + user.get_IP() + "=" + this->get_name() + ":";
	for (size_t i = 0; i < this->connected_users.size(); i++)
	{
		if (this->is_op(*(this->connected_users[i])))
			tosend += "@";
		tosend += this->connected_users[i]->get_name() + " ";	
	};
	stoc(user.get_fd(), tosend + "\r\n");
	stoc(user.get_fd(), RPL_ENDOFNAMES + user.get_name() + "!" + user.get_real() + "@" + user.get_IP() + " " + this->get_name() + " :End of /NAMES list\r\n");
	
};

void	Channel::who_cmd(Server& server, int client_fd)
{
	User& user = server.get_user(client_fd);
	
	for (size_t i = 0; i < this->connected_users.size(); i++)
	{
		std::string tosend = RPL_WHOREPLY + user.get_name() + "!" + user.get_real() + "@" + user.get_IP() + " " + this->get_name() + " "
		+ this->connected_users[i]->get_name() + " " + this->connected_users[i]->get_IP() + " "
		+ server.get_ip() + " " + this->connected_users[i]->get_name() + " H";

		if (this->is_op(*(this->connected_users[i])))
			tosend += "@";
		stoc(user.get_fd(), tosend + " :0 " + this->connected_users[i]->get_real() + "\r\n");		
	};
	stoc(user.get_fd(), RPL_ENDOFWHO + user.get_name() + "!" + user.get_real() + "@" + user.get_IP() + " :End of /NAMES list\r\n");
	
};

void	Channel::send_to_all(std::string msg)
{
	for (size_t i = 0; i < this->connected_users.size(); i++)
		stoc(this->connected_users[i]->get_fd(), msg);	
};

void	Channel::user_to_all(int sender_fd, std::string msg)
{
	for (size_t i = 0; i < this->connected_users.size(); i++)
	{
		if (this->connected_users[i]->get_fd() != sender_fd)
			stoc(this->connected_users[i]->get_fd(), msg);	
	}
};
void			Channel::set_topic(std::string topic)
{
	this->_topic = topic;
	for (size_t i = 0; i < this->connected_users.size(); i++)
		stoc(this->connected_users[i]->get_fd(), RPL_TOPIC + this->connected_users[i]->get_name() + " " + this->_name + " :" + topic + "\r\n");
};

void			Channel::mode_switch(char c)
{
	switch(c)
	{
		case 'i':
			this->_inv_only = !this->_inv_only;
			break;
		case 't':
			this->_restr_topic = !this->_restr_topic;
			break;
	}
};
