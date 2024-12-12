/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:16:24 by kpoilly           #+#    #+#             */
/*   Updated: 2024/12/11 15:17:02 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include "ft_irc.hpp"

class User;
class Server;

class Channel
{
	private:
		std::string _name;
		std::string _topic;
		std::string _password;

		bool		_inv_only;
		bool		_restr_topic;
		size_t		_limit;
		
		std::vector<std::string>	_invited_users;
		std::vector<User*> 			_op_users;

		void	_add_user(User& user);

	public:
		std::vector<User*> 			connected_users;

		Channel(std::string name);
		Channel(const Channel& copy);
		Channel& operator=(const Channel& copy);
		~Channel();

		std::string		get_name();
		std::string		get_topic();
		std::string		get_nb_users_str();

		void			_remove_user(User& user);
		void			set_password(std::string password);
		void			set_limit(size_t lim);

		bool			is_op(User& user);
		bool			is_connected(User& user);
		bool			is_invited(User& user);
		
		bool			is_topic_restr();
		bool			is_passworded();
		bool			is_invite_only();
		bool			is_cap_limited();

		void			_add_op(User& user);
		void			_remove_op(User& user);
		void			add_invited(std::string username);
		void			remove_invited(std::string username);
		void			set_topic(std::string topic);
		
		void			mode_switch(char c);


		void	join(User& user, std::string password);
		void	part(User& user, std::string part_msg);
		void	send_connected_users(User& user);
		void	who_cmd(Server& server, int client_fd);
		void	send_to_all(std::string msg);
		void	user_to_all(int sender_fd, std::string msg);
};

#endif