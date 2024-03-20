/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:06:36 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/20 09:37:06 by kpoilly          ###   ########.fr       */
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
		Contact contacts[8];
		int		pb_size;
};