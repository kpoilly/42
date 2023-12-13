/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:07:02 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/11 18:14:20 by kpoilly          ###   ########.fr       */
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
	Contact newcontact(nbcontacts);
	contacts.push_back(newcontact);
}

void PhoneBook::display()
{
	int i;
	int input;
	
	for (i = 0; i < contacts.size(); i++)
	{
		contacts[i].info_summary();
	}
	if (!i)
	{
		cout<<"Phonebook is empty."<<endl;
		return ;
	}
	
	cout<<"\nContact index: ";
	cin>>input;
	contacts[input].display_info();
}