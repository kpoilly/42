/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:07:02 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/21 12:48:59 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_awesome_phonebook.hpp"

PhoneBook::PhoneBook():_contacts(), _pb_size(0){}

PhoneBook::PhoneBook(Contact newcontact)
{
	_contacts[_pb_size % 8] = newcontact;
	this->_pb_size++;
}

void PhoneBook::add()
{
	Contact newcontact(_pb_size % 8);
	_contacts[_pb_size % 8] = newcontact;
	this->_pb_size++;
	std::cout<<"\nAdded! :)"<<std::endl;
	sleep(1);
}

void PhoneBook::display()
{
	std::string	input;
	
	if (!_pb_size)
	{
		std::cout<<"Phonebook is empty."<<std::endl;
		return ;
	}
	int nb = _pb_size;
	if (nb > 8)
		nb = 8;
	for (int i = 0; i < nb; i++)
		_contacts[i].info_summary();
	std::cout<<std::endl;
	do {
		std::cout<<"Contact index: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(1);
	} while (input.empty() || !isnumber(input) || input.size() > 2  ||  std::stoi(input) >= nb);
	_contacts[std::stoi(input)].display_info();
}