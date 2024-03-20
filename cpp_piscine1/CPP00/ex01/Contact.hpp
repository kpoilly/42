/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:05:37 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/20 09:36:37 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_awesome_phonebook.hpp"

class Contact
{
	public:
		Contact();
		Contact(int nb);
		void info_summary();
		void display_info();
	
	private:
		int	index;
		std::string name;
		std::string lastname;
		std::string nickname;
		std::string phnumber;
		std::string darksecret;
};