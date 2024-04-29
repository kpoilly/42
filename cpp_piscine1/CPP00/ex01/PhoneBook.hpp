/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:06:36 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/29 16:59:51 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "my_awesome_phonebook.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		PhoneBook(Contact newcontact);
		void add();
		void display();
	
	private:
		Contact _contacts[8];
		int		_pb_size;
};

#endif