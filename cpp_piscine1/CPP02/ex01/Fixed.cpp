/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:52:27 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/06 12:04:51 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

fixed::fixed():_value(0)
{std::cout << "Default Constructor called." <<std::endl;};

fixed::fixed(const int nb):_value(nb << this->_frac)
{std::cout << "Int Constructor called." <<std::endl;}

fixed::fixed(const float nb)
{
	std::cout << "Float Constructor called." <<std::endl;
	this->_value = roundf(nb * (1 << this->_frac));
}
fixed::fixed(const fixed& nb)
{
	std::cout << "Copy Constructor called." <<std::endl;
	this->_value = nb._value;
}
fixed::~fixed()
{
	std::cout << "Destructor called." <<std::endl;
}

fixed& fixed::operator=(const fixed& nb)
{
	std::cout << "Copy assignement operator called (=)." <<std::endl;
	this->_value = nb._value;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const fixed& nb)
{
	os << nb.toFloat();
	return (os);
}

int fixed::getRawBits(void) const
{
	std::cout << "getRawBits member called :" << std::endl;
	return (this->_value);
}
void fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member called." << std::endl;
	this->_value = raw;
}

float fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << this->_frac));
}

int fixed::toInt(void) const
{
	return (this->_value >> this->_frac);
}
