/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:07:02 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/20 10:12:19 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_awesome_phonebook.hpp"

PhoneBook::PhoneBook():contacts(), pb_size(0){}

PhoneBook::PhoneBook(Contact newcontact)
{
	contacts[pb_size] = newcontact;
	this->pb_size++;
}

void PhoneBook::add(int nbcontacts)
{
	if (pb_size < 8)
	{
		Contact newcontact(nbcontacts);
		contacts[pb_size] = newcontact;
		this->pb_size++;
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
	
	for (i = 0; i < pb_size; i++)
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
	} while (!isnumber(input) || input.size() > 2  ||  stoi(input) >= pb_size);
	contacts[std::stoi(input)].display_info();
}