/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:52:27 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/18 08:30:29 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

fixed::fixed():value(0)
{std::cout << "Default Constructor called." <<std::endl;};

fixed::fixed(const int nb):value(nb * pow(2, this->frac))
{std::cout << "Int Constructor called." <<std::endl;}

fixed::fixed(const float nb)
{
	std::cout << "Float Constructor called." <<std::endl;
	float temp;
	int conv;
	
	temp = nb * pow(2, this->frac);
	conv = int(round(temp));

	if (temp < 0)
	{
		conv = abs(conv);
		conv = ~conv;
		conv = conv + 1;
	}
	this->value = conv;
}
fixed::fixed(const fixed& nb)
{
	std::cout << "Copy Constructor called." <<std::endl;
	this->value = nb.value;
}
fixed::~fixed()
{
	std::cout << "Destructor called." <<std::endl;
}

fixed& fixed::operator=(const fixed& nb)
{
	std::cout << "Copy assignement operator called (=)." <<std::endl;
	this->value = nb.value;
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
	return (this->value);
}
void fixed::setRawBits(int const raw)
{
	std::cout << "getRawBits member called." << std::endl;
	this->value = raw;
}

float fixed::toFloat(void) const
{
	float res;
	
	res = (float)this->value * 1.0;
	res /= pow(2, this->frac);

	return (res);
}

int fixed::toInt(void) const
{
	return ((int)this->toFloat());
}
