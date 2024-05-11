/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:52:27 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/10 10:15:08 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

fixed::fixed():_value(0)
{//std::cout << "Default Constructor called." <<std::endl;
}

fixed::fixed(const int nb):_value(nb << this->_frac)
{//std::cout << "Int Constructor called." <<std::endl;
}

fixed::fixed(const float nb)
{
	//std::cout << "Float Constructor called." <<std::endl;
	this->_value = roundf(nb * (1 << this->_frac));
}
fixed::fixed(const fixed& nb)
{
	//std::cout << "Copy Constructor called." <<std::endl;
	*this = nb;
}
fixed::~fixed()
{
	//std::cout << "Destructor called." <<std::endl;
}

fixed& fixed::operator=(const fixed& nb)
{
	//std::cout << "Copy assignement operator called (=)." <<std::endl;
	this->_value = nb.getRawBits();
	return (*this);
}

bool fixed::operator> (const fixed& other)
{
	return(this->toFloat() > other.toFloat());
}

bool fixed::operator< (const fixed& other)
{
	return(this->toFloat() < other.toFloat());
}

bool fixed::operator>= (const fixed& other)
{
	return(this->toFloat() >= other.toFloat());
}

bool fixed::operator<= (const fixed& other)
{
	return(this->toFloat() <= other.toFloat());
}

bool fixed::operator== (const fixed& other)
{
	return(this->toFloat() == other.toFloat());
}

bool fixed::operator!= (const fixed& other)
{
	return(this->toFloat() != other.toFloat());
}

fixed& fixed::operator+ (const fixed& other)
{
	double value = this->toFloat() + other.toFloat();
	fixed *res = new fixed((float)value);
	return (*res);
}

fixed& fixed::operator- (const fixed& other)
{
	double value = this->toFloat() - other.toFloat();
	fixed *res = new fixed((float)value);
	return (*res);
}

fixed& fixed::operator* (const fixed& other)
{
	double value = this->toFloat() * other.toFloat();
	fixed *res = new fixed((float)value);
	return (*res);
}

fixed& fixed::operator/ (const fixed& other)
{
	double value = this->toFloat() / other.toFloat();
	fixed *res = new fixed((float)value);
	return (*res);
}

fixed& fixed::operator++ (int)
{
	fixed *tmp = new fixed();
	tmp->setRawBits(this->_value);
	this->_value++;
	return (*tmp);
}

fixed& fixed::operator++ ()
{
	this->_value++;
	return (*this);
}

fixed& fixed::operator-- (int)
{
	fixed *tmp = new fixed();
	tmp->setRawBits(this->_value);
	this->_value--;
	return (*tmp);
}

fixed& fixed::operator-- ()
{
	this->_value--;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const fixed& nb)
{
	os << nb.toFloat();
	return (os);
}

int fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member called :" << std::endl;
	return (this->_value);
}
void fixed::setRawBits(int const raw)
{
	//std::cout << "getRawBits member called." << std::endl;
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

fixed& fixed::min (fixed& a, fixed& b)
{
	return (a._value <= b._value ? a : b);
}

const fixed& fixed::min (const fixed& a, const fixed& b)
{
	return (a._value <= b._value ? a : b);
}

fixed& fixed::max (fixed& a, fixed& b)
{
	return (a._value >= b._value ? a : b);
}

const fixed& fixed::max (const fixed& a, const fixed& b)
{
	return (a._value >= b._value ? a : b);
}

int fixed::toFixed(float nb)
{
	return (roundf(nb * (1 << this->_frac)));
}