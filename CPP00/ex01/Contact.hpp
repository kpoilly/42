/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:05:37 by kpoilly           #+#    #+#             */
/*   Updated: 2024/04/29 16:59:28 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "my_awesome_phonebook.hpp"

class Contact
{
	public:
		Contact();
		Contact(int nb);
		void info_summary();
		void display_info();
	
	private:
		int	_index;
		std::string _name;
		std::string _lastname;
		std::string _nickname;
		std::string _phnumber;
		std::string _darksecret;
};

#endif