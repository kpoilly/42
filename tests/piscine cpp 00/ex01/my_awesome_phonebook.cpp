/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_awesome_phonebook.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:11:01 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/11 18:46:29 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_awesome_phonebook.hpp"

void help(void)
{
	cout<<"ADD: create a new contact.\nSEARCH: display a specific contact.\nEXIT: quit.\nHELP: well...\n"<<endl;
}

void interface(PhoneBook book, int *nbcontacts)
{
	string input;

	cout<<"------------------"<<endl;
	cout<<"\nPlease use one of the 3 commands below\nADD, SEARCH, EXIT\n(you can also use HELP to get informations about what they do)\n"<<endl;
	cin >> input;
	
	if (input == "HELP")
	{
		help();
		cout<<"Type anything to go back.";
		cin >> input;
		interface(book, nbcontacts);
	}
	else if (input == "ADD")
	{
		book.add(*nbcontacts);
		(*nbcontacts)++;
		interface(book, nbcontacts);
	}
	else if (input == "SEARCH")
	{
		book.display();
		cout<<"Type anything to go back.";
		cin >> input;
		interface(book, nbcontacts);
	}
	else if (input == "EXIT")
		return ;
}

int main(void)
{
	int nbcontacts = 0;
	PhoneBook book;
	interface(book, &nbcontacts);
	return(0);
}