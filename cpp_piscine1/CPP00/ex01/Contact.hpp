/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:05:37 by kpoilly           #+#    #+#             */
/*   Updated: 2024/02/08 16:20:14 by kpoilly          ###   ########.fr       */
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