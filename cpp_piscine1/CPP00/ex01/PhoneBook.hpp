/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:06:36 by kpoilly           #+#    #+#             */
/*   Updated: 2024/02/08 16:21:07 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_awesome_phonebook.hpp"

class PhoneBook
{
	public:
	PhoneBook();
	PhoneBook(Contact newcontact);
	void add(int nbcontacts);
	void display();
	
	private:
	std::vector <Contact> contacts;
};