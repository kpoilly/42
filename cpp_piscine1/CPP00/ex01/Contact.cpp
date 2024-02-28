/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:01:26 by kpoilly           #+#    #+#             */
/*   Updated: 2024/02/13 12:52:00 by kpoilly          ###   ########.fr       */
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

	std::cout<<"Phone Number : ";
	std::getline(std::cin, phnumber);

	std::cout<<"Darkest secret : ";
	std::getline(std::cin, darksecret);
}

void Contact::info_summary()
{
	std::cout<<index; std::cout<<": ";
	std::cout<<name + " | ";
	std::cout<<lastname + " | ";
	std::cout<<nickname<<std::endl;
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