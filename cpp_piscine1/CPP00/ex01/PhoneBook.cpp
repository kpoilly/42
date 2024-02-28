/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:07:02 by kpoilly           #+#    #+#             */
/*   Updated: 2024/02/26 11:06:36 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_awesome_phonebook.hpp"

PhoneBook::PhoneBook():contacts(){}

PhoneBook::PhoneBook(Contact newcontact)
{
	contacts.push_back(newcontact);
}

void PhoneBook::add(int nbcontacts)
{
	if (contacts.size() < 8)
	{
		Contact newcontact(nbcontacts);
		contacts.push_back(newcontact);
	}
	else
	{
		Contact newcontact(7);
		contacts[7] = newcontact;
	}
	std::cout<<"\nAdded! :)"<<std::endl;
	sleep(1);
}

void PhoneBook::display()
{
	int 		i;
	std::string	input;
	
	for (i = 0; i < contacts.size(); i++)
		contacts[i].info_summary();
	if (!i)
	{
		std::cout<<"Phonebook is empty."<<std::endl;
		return ;
	}
	std::cout<<"\n";
	do {
		std::cout<<"Contact index: ";
		std::getline(std::cin, input);
	} while (!isnumber(input) || stoi(input) < contacts.size());
	contacts[std::stoi(input)].display_info();
}