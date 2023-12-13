/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:05:37 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/11 18:07:20 by kpoilly          ###   ########.fr       */
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
	string name;
	string lastname;
	string nickname;
	string phnumber;
	string darksecret;
};