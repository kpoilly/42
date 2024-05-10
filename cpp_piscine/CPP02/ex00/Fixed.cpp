/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:52:27 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/06 12:36:31 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

fixed::fixed()
{
	std::cout << "Default Constructor called." <<std::endl;
	this->_value = 0;
}
fixed::fixed(fixed& nb)
{
	std::cout << "Copy Constructor called." <<std::endl;
	*this = nb;
}
fixed::~fixed()
{
	std::cout << "Destructor called." <<std::endl;
}

fixed& fixed::operator=(const fixed& nb)
{
	std::cout << "Copy assignement operator called (=)." <<std::endl;
	this->_value = nb.getRawBits();
	return (*this);
}

int fixed::getRawBits(void) const
{
	std::cout << "getRawBits member called." << std::endl;
	return (this->_value);
}
void fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member called." << std::endl;
	this->_value = raw;
}
