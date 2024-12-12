/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:16:24 by kpoilly           #+#    #+#             */
/*   Updated: 2024/12/11 13:56:24 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.hpp"

//Constructors-Destructors
Message::Message(std::string const & content)
{
	std::vector<std::string>	elements;
	std::stringstream			stream(content, std::stringstream::in);
	std::string					element;

	while (stream >> element)
		elements.push_back(element);

	if (elements.size() == 0 || (elements.size() == 1 && elements[0][0] == ':'))
		throw Parsing(461);
	
	
	if (elements[0][0] == ':')
	{
		this->_prefix = elements[0];
		this->_command = elements[1];
	}
	else
	{
		this->_prefix = "";
		this->_command = elements[0];
	}

	elements.erase(elements.begin());
	//elements.erase(elements.begin());

	std::vector<std::string>::const_iterator it;
	for (it = elements.begin(); it < elements.end(); ++it)
		this->_parameters.push_back(*it);
};

Message::~Message() {};
//------


//Operator overloads
Message& Message::operator=(const Message& copy)
{
	_prefix = copy._prefix;
	_command = copy._command;
	_parameters = copy._parameters;

	return *this;
};
//------

std::string Message::get_prefix() const
{
	return _prefix;
};
std::string Message::get_command() const
{
	return _command;
};
std::vector<std::string> Message::get_parameters() const
{
	return _parameters;
};


//Utils
std::string Message::get_content()
{
	std::string							params;
	std::vector<std::string>::const_iterator	it;
	for (it = _parameters.begin(); it< _parameters.end(); ++it)
		params += *it + " ";
	return _prefix + " " + _command + " " + params;
};

std::string	Message::get_param(size_t i)
{
	if (i >= this->_parameters.size())
		throw Parsing(461);
	return _parameters[i];
};

int			Message::get_nbparam()
{
	return this->_parameters.size();
};


