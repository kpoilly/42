/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:13:54 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/09 10:11:50 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria()
{
	_Type = "ice";
};

Ice::Ice(const Ice& copy)
{
	*this = copy;
};

const Ice& Ice::operator=(const Ice& copy)
{
	return (*(copy.clone()));
};

Ice::~Ice(){};

void Ice::use(ICharacter& target)
{
	std::cout << "shoots an \033[1;36mice bolt\033[0m at \033[1;31m";
	std::cout << target.getName() << "\033[0m *" << std::endl;
};

Ice* Ice::clone() const
{
	Ice *copy = new Ice();
	copy = (Ice *)this;
	return (copy);
};