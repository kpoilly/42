/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:01:26 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/20 10:45:12 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_awesome_phonebook.hpp"

Contact::Contact():index(0), name(), lastname(), nickname(), phnumber(), darksecret(){}
Contact::Contact(int nb)
{
	index = nb;
	
	std::cout<<"Name : ";
	std::getline(std::cin, name);

	std::cout<<"Lastname : ";
	std::getline(std::cin, lastname);

	std::cout<<"Nickname : ";
	std::getline(std::cin, nickname);

	do
	{
		std::cout<<"Phone Number : ";
		std::getline(std::cin, phnumber);
	} while (!isnumber(phnumber));
	
	std::cout<<"Darkest secret : ";
	std::getline(std::cin, darksecret);
}

void Contact::info_summary()
{
	std::string format_name = name;
	std::string format_lname = lastname;
	std::string format_nname = nickname;

	if (name.size() > 10)
		format_name = name.substr(0, 9) + ".";
	if (lastname.size() > 10)
		format_lname = lastname.substr(0, 9) + ".";
	if (nickname.size() > 10)
		format_nname = nickname.substr(0, 9) + ".";
	
	std::cout<<index; std::cout<<": ";
	std::cout << std::setw(13);
	std::cout<<format_name + " | ";
	std::cout << std::setw(13);
	std::cout<<format_lname + " | ";
	std::cout << std::setw(10);
	std::cout<<format_nname<<std::endl;
}

void Contact::display_info()
{
	std::cout<<"\n";
	std::cout<<"Name : " + name<<std::endl;
	std::cout<<"Lastname : " + lastname<<std::endl;
	std::cout<<"Nickname : " + nickname<<std::endl;
	std::cout<<"Phone Number : " + phnumber<<std::endl;
	std::cout<<"Darkest secret : " + darksecret + "\n"<<std::endl;
}