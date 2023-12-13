/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:01:26 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/11 18:15:52 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_awesome_phonebook.hpp"

Contact::Contact():index(0), name(), lastname(), nickname(), phnumber(), darksecret(){}
Contact::Contact(int nb)
{
	index = nb;
	
	cout<<"Name : ";
	cin >> name;

	cout<<"Lastname : ";
	cin >> lastname;

	cout<<"Nickname : ";
	cin >> nickname;

	cout<<"Phone Number : ";
	cin >> phnumber;

	cout<<"Darkest secret : ";
	cin >> darksecret;
}

void Contact::info_summary()
{
	cout<<index; cout<<": ";
	cout<<name + " | ";
	cout<<lastname + " | ";
	cout<<nickname<<endl;
}

void Contact::display_info()
{
	cout<<"Name : " + name<<endl;
	cout<<"Lastname : " + lastname<<endl;
	cout<<"Nickname : " + nickname<<endl;
	cout<<"Phone Number : " + phnumber<<endl;
	cout<<"Darkest secret : " + darksecret + "\n"<<endl;
}