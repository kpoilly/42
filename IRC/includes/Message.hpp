/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:16:24 by kpoilly           #+#    #+#             */
/*   Updated: 2024/12/11 13:54:47 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_HPP
# define MESSAGE_HPP

# define ERR_UNKNOWNCOMMAND	421

# include "ft_irc.hpp"

class Message
{
	private:
		std::string					_prefix;	// optional
		std::string					_command;	// e.g. JOIN, PRIVMSG, PING
		std::vector<std::string>	_parameters;// e.g. message content

	public:
		//Constructors-Destructors
		Message(std::string const & message);
		~Message();
		
		//Operator overloads
		Message& operator=(const Message& copy);

		//Utils
		std::string	get_content();
		std::string	get_param(size_t i);
		int			get_nbparam();

		//Getters
		std::string					get_prefix() const;
		std::string					get_command() const;
		std::vector<std::string>	get_parameters() const;

		//Exceptions
		class Parsing : public std::exception {
			public:
				Parsing(int type) throw() : _type(type) {}
				~Parsing() throw() {}

				int get_type() const { return _type; }

			private:
				int _type;
		};
};

#endif