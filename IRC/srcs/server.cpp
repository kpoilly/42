/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:30:58 by kpoilly           #+#    #+#             */
/*   Updated: 2024/12/11 16:52:31 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.hpp"

//Setup
Server::Server(int port, std::string const & password)
{
//Open socket on a file descriptor
	this->_ip = "127.0.0.1";
	this->_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (this->_fd < 0)
	{
		std::perror("socket()");
		throw std::exception();
	}

	//Configure socket and password
	this->_port = port;
	this->_address.sin_family = AF_INET;
	this->_address.sin_port = htons(this->_port);
	this->_address.sin_addr.s_addr = INADDR_ANY;
	this->_password = password;
	this->_motd = ":AlKi 372 Bienvenue sur Discord 2.0!";

	//Add socket options
	this->_socket_options = 1;
	if (setsockopt(this->_fd, SOL_SOCKET, SO_REUSEADDR,
		&this->_socket_options,  sizeof(_socket_options)) < 0)
	{
		close(this->_fd);
		std::perror("setsockopt()");
		throw std::exception();
	}

	//Bing socket on a network and a port
	if (bind(this->_fd, (struct sockaddr*)&this->_address, sizeof(this->_address)))
	{
		close(this->_fd);
		std::perror("bind()");
		throw std::exception();
	}

	//Open slots for clients connections
	if (listen(this->_fd, 42) < 0)
	{
		close(this->_fd);
		std::perror("listen()");
		throw std::exception();
	}

	//Add server fd in the pollfd
	pollfd serverPollfd = {this->_fd, POLLIN, 0};
	this->_pollfd.push_back(serverPollfd);

	std::cout << "\033[1;32mServer is up and listening on port " << port << "\033[0m" << std::endl;

	this->_motd = "Bienvenue sur Discord 2.0!";
};

Server::~Server()
{
	for (size_t i = 0; i < this->_channels_list.size(); ++i)
		delete this->_channels_list[i];
	this->_channels_list.clear();

	for (size_t i = 0; i < this->_users_list.size(); ++i)
		delete this->_users_list[i];
	this->_users_list.clear();


	std::vector<pollfd>::iterator pollfd = this->_pollfd.begin();
	++pollfd;
	for (; pollfd < this->_pollfd.end(); ++pollfd)
	{
		std::string quit_msg = ":localhost QUIT :Server shutting down\n";
		send(pollfd->fd, quit_msg.c_str(), quit_msg.length(), 0);
		close(pollfd->fd);
	}
	close(this->_pollfd.begin()->fd);
	this->_pollfd.clear();
};

//Getters
int Server::get_servfd()
{
	return this->_fd;
};

std::string Server::get_ip()
{
	return this->_ip;
};

int Server::get_port() const
{
	return this->_port;
};

std::string Server::get_password()
{
	return this->_password;
};

std::vector<Channel*> Server::get_channels_list()
{
	return this->_channels_list;
};

std::vector<User*> Server::get_users_list()
{
	return this->_users_list;
};

pollfd& Server::get_pollfd(int fd)
{
	std::vector<pollfd>::iterator it;
	for(it = this->_pollfd.begin(); it < this->_pollfd.end(); ++it)
	{
		pollfd& pollfd = *it;
		if (pollfd.fd == fd)
			return pollfd;
	};
	return this->_pollfd.at(0);
};

User& Server::get_user(int fd)
{
	std::vector<User*>::iterator it;
	for(it = this->_users_list.begin(); it < this->_users_list.end(); ++it)
	{
		User* user = *it;
		if (user->get_fd() == fd)
			return *user;
	};
	return *_users_list.at(0);
};

User& Server::get_user(std::string name)
{
	std::vector<User*>::iterator it;
	for(it = this->_users_list.begin(); it < this->_users_list.end(); ++it)
	{
		User* user = *it;
		if (user->get_name() == name)
			return *user;
	};
	return *_users_list.at(0);
};

Channel& Server::get_channel(std::string name)
{
	std::vector<Channel*>::iterator it;
	for(it = this->_channels_list.begin(); it < this->_channels_list.end(); ++it)
	{
		Channel* channel = *it;
		if (channel->get_name() == name)
			return *channel;
	};
	return *_channels_list.at(0);
};

std::string Server::get_motd()
{
	return this->_motd;
};

std::vector<pollfd> Server::get_pollfd_list() const
{
	return this->_pollfd;
};

//Utils
void	Server::loop()
{
	while (true)
	{
		int poll_status = this->open_poll();
		if (poll_status == -1)
			throw std::exception();

		std::vector<pollfd>::iterator it = _pollfd.begin();
		for (; poll_status > 0 && it != _pollfd.end(); --poll_status) {
			bool	clientDisconnect = false;
			if (it->revents == 0)
			{
				++it;
				++poll_status;
				continue;
			}
			try
			{
				this->handle_poll(*it);
			}
			catch (Server::UserQuit)
			{
				it = this->user_quit(it);
				clientDisconnect = true;
				std::cout << SERV <<"User disconnected.\n";
			}
			catch (std::runtime_error)
			{
				continue;
			}
			catch (std::exception)
			{
				throw;
			}
			if (!clientDisconnect)
				++it;
		}
		
	}
}

int Server::open_poll()
{
	return poll(this->_pollfd.data(), this->_pollfd.size(), -1); // -1: no timeout
}

void Server::handle_poll(pollfd it)
{
	if (it.revents & POLLIN) { // There is something to read
		if (it.fd == this->_fd) { // Read from server = new user to accept
			sockaddr address;
    		socklen_t size = sizeof(address); // Declare and initialize the size variable.

    		memset(&address, 0, sizeof(address)); // Clear the address structure.
			int	fd = accept(this->_fd, &address, &size);
			if (fd < 0)
			{
				std::perror("accept");
				return ;
			}
			User* newUser = new User(fd);
			this->add_user(newUser);
		}
		else { // Read from user
			char buffer[1024];
			ssize_t bytes_read = recv(it.fd, buffer, sizeof(buffer) - 1, 0);

			if (bytes_read <= 0) // Disconnection message
			{
				if (bytes_read == -1)
					std::perror("recv");
				throw UserQuit();
			}
			else // Messages
			{
				buffer[bytes_read] = '\0';
				std::string new_buffer = get_user(it.fd).get_buffer() + buffer;
				get_user(it.fd).set_buffer(new_buffer);

				if (std::strstr(new_buffer.c_str(), "\r\n") != NULL)
				{
					this->communicate(get_user(it.fd));
				}	
			}
		}
	}
}


void Server::communicate(User & user)
{
	std::size_t	pos = 0;
	while (true)
	{
		std::string	buf = user.get_buffer();
		std::size_t	end = buf.find("\r\n", pos);
		if (end == std::string::npos) break;

		std::string	cmd_line = buf.substr(pos, end - pos);
		Message message(cmd_line);
		parsing(*this, user.get_fd(), message);
		pos = end + 1;
	}
	user.set_buffer(user.get_buffer().substr(pos));
}

std::vector<pollfd>::iterator Server::user_quit(std::vector<pollfd>::iterator & it)
{
	close(it->fd);

	this->remove_user(it->fd);
	return this->_pollfd.erase(it);
};

void Server::add_channel(std::string name, std::string password)
{
	if (this->channel_exists(name))
		return;
	std::cout << SERV << "New channel " << name << " created!" << std::endl;
	Channel *toadd = new Channel(name);
	this->_channels_list.push_back(toadd);
	if (!password.empty())
		toadd->set_password(password);
};

void	Server::remove_channel(std::string name)
{
	for (size_t i = 0; i < this->_channels_list.size(); i++)
	{
		if (this->_channels_list[i]->get_name() == name)
		{
			delete this->_channels_list[i];
			this->_channels_list.erase(this->_channels_list.begin() + i);
			break;
		}
	}
};

bool	Server::channel_exists(std::string name)
{
	for (std::vector<Channel*>::iterator it = this->_channels_list.begin(); it != this->_channels_list.end();)
	{
		if ((**it).get_name() == name)
			return true;
		it++;
	};
	return false;
};

void	Server::add_user(User *user)
{
	this->_users_list.push_back(user);
	pollfd user_pollfd = {user->get_fd(), POLLIN, 0};
	this->_pollfd.push_back(user_pollfd);
};

void	Server::remove_user(int fd)
{
	std::vector<User*>::iterator it;
	for(it = this->_users_list.begin(); it < this->_users_list.end(); ++it)
	{
		User* user = *it;
		if (user->get_fd() == fd)
		{
			delete user;
			this->_users_list.erase(it);
			return;
		}
	};
};

bool	Server::check_nick(std::string name, int client_fd)
{
	for(size_t i = 0; i < this->_users_list.size(); i++)
	{
		if ((this->_users_list[i]->get_name() == name || (this->_users_list[i]->get_name() + "\r") == name)
			&& client_fd != this->_users_list[i]->get_fd())
			return false;
	}
	return true;
};

bool	Server::nick_exists(std::string name)
{
	for(size_t i = 0; i < this->_users_list.size(); i++)
	{
		if (this->_users_list[i]->get_name() == name)
			return true;
	}
	return false;
};

void	Server::send_to_all(std::string arg)
{
	for(size_t i = 0; i < this->_users_list.size(); i++)
		stoc(this->_users_list[i]->get_fd(), arg);
};

void	Server::disconnectServer()
{
	std::vector<pollfd>::iterator pollfds = this->_pollfd.begin();
	++pollfds;

	// Loop through all users to send a disconnect message and close fd
	for (; pollfds < this->_pollfd.end(); ++pollfds)
	{
		std::string quit_msg = ":AlKi QUIT :Server shutting down\n";
		send(pollfds->fd, quit_msg.c_str(), quit_msg.length(), 0);
		close(pollfds->fd);
	}

	close(this->_pollfd[0].fd);
	this->_users_list.clear();
	this->_pollfd.clear();
};
