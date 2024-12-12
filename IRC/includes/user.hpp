/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:17:53 by kpoilly           #+#    #+#             */
/*   Updated: 2024/12/10 22:29:07 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_HPP
# define USER_HPP

# include "ft_irc.hpp"

class User
{
	private:
		std::string		_name;
		std::string		_ipAddress;
		std::string		_realname;
		int				_clientfd;
		bool			_is_authenticated;

		std::string		_buffer;
		
		std::vector<Channel*>	_joined_channels;

	public:
		User(int fd);
		~User();

		bool		is_authenticated();
		std::string	get_buffer();
		std::string	get_name();
		std::string	get_IP();
		std::string	get_real();
		int			get_fd();
		std::vector<Channel*> get_joined();

		void		authenticate();
		void		set_buffer(std::string const & content);
		void		set_name(std::string name);
		void		set_IP(std::string IP);
		void		set_real(std::string real);
		void		set_fd(int fd);

		void		join_channel(Channel& channel);
		void		leave_channel(Channel& channel);
};

#endif