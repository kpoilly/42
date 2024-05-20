/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:13:54 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/09 12:03:23 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice"){};

Ice::Ice(const Ice& copy) : AMateria("ice")
{
	*this = copy;
};

const Ice& Ice::operator=(const Ice& copy)
{
	this->_Type = copy._Type;
	return (*this);
};

Ice::~Ice(){};

void Ice::use(ICharacter& target)
{
	std::cout << "shoots an \033[1;36mice bolt\033[0m at \033[1;31m";
	std::cout << target.getName() << "\033[0m *" << std::endl;
};

Ice* Ice::clone() const
{
	Ice *copy = new Ice(*this);
	return (copy);
};