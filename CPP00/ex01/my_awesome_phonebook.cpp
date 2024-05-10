/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_awesome_phonebook.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:11:01 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/10 06:57:13 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_awesome_phonebook.hpp"

int	isnumber(std::string s)
{
	for (int i = 0; s[i]; i++)
		if (!std::isdigit(s[i]))
			return (0);
	return (1);
}

void help(void)
{
	std::cout<<"ADD: create a new contact.\nSEARCH: display a specific contact.\nEXIT: quit.\nHELP: well...\n"<<std::endl;
}

void interface(PhoneBook book)
{
	std::string input;
	
	while (input != "EXIT")
	{
		std::cout<<"\033[2J\033[;H"<<"------------------"<<std::endl;
		std::cout<<"\nPlease use one of the 3 commands below\nADD, SEARCH, EXIT\n(you can also use HELP to get informations about what they do)\n"<<std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			break;
		for(unsigned long i = 0; i < input.length(); i++)
			input[i] = toupper(input[i]);
		
		if (input == "HELP")
		{
			help();
			std::cout<<"Type anything to go back.";
			std::getline(std::cin, input);
		}
		else if (input == "ADD")
			book.add();
		else if (input == "SEARCH")
		{
			book.display();
			std::cout<<"Type anything to go back.";
			std::getline(std::cin, input);
		}
	}
}

int main(void)
{
	PhoneBook book;
	interface(book);
	return(0);
}