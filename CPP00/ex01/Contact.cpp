/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:01:26 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/21 10:55:31 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_awesome_phonebook.hpp"

Contact::Contact():_index(0){}
Contact::Contact(int nb)
{
	_index = nb;
	
	std::cout<<"Name : ";
	std::getline(std::cin, _name);

	std::cout<<"Lastname : ";
	std::getline(std::cin, _lastname);

	std::cout<<"Nickname : ";
	std::getline(std::cin, _nickname);

	do
	{
		std::cout<<"Phone Number : ";
		std::getline(std::cin, _phnumber);
	} while (!isnumber(_phnumber));
	
	std::cout<<"Darkest secret : ";
	std::getline(std::cin, _darksecret);
}

void Contact::info_summary()
{
	std::string format_name = _name;
	std::string format_lname = _lastname;
	std::string format_nname = _nickname;

	if (_name.size() > 10)
		format_name = _name.substr(0, 9) + ".";
	if (_lastname.size() > 10)
		format_lname = _lastname.substr(0, 9) + ".";
	if (_nickname.size() > 10)
		format_nname = _nickname.substr(0, 9) + ".";
	
	std::cout << std::setw(12);
	std::cout<<_index; std::cout<<": ";
	std::cout << std::setw(13);
	std::cout<<format_name + " | ";
	std::cout << std::setw(13);
	std::cout<<format_lname + " | ";
	std::cout << std::setw(10);
	std::cout<<format_nname<<std::endl;
}

void Contact::display_info()
{
	std::cout<<std::endl;
	std::cout<<"Name : " + _name<<std::endl;
	std::cout<<"Lastname : " + _lastname<<std::endl;
	std::cout<<"Nickname : " + _nickname<<std::endl;
	std::cout<<"Phone Number : " + _phnumber<<std::endl;
	std::cout<<"Darkest secret : " + _darksecret + "\n"<<std::endl;
}