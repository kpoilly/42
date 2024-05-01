/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:52:27 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/01 13:46:33 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

fixed::fixed():_value(0)
{//std::cout << "Default Constructor called." <<std::endl;
}

fixed::fixed(const int nb):_value(nb * 256)
{//std::cout << "Int Constructor called." <<std::endl;
}

fixed::fixed(const float nb)
{
	//std::cout << "Float Constructor called." <<std::endl;
	
	long temp = nb * 256; //pow(2, this->frac);
	int conv = int(roundf(temp));
	this->_value = conv;
}
fixed::fixed(const fixed& nb)
{
	//std::cout << "Copy Constructor called." <<std::endl;
	this->_value = nb._value;
}
fixed::~fixed()
{
	//std::cout << "Destructor called." <<std::endl;
}

fixed& fixed::operator=(const fixed& nb)
{
	//std::cout << "Copy assignement operator called (=)." <<std::endl;
	this->_value = nb._value;
	return (*this);
}

bool fixed::operator> (const fixed& other)
{
	return(this->toInt() > other.toInt());
}

bool fixed::operator< (const fixed& other)
{
	return(this->toInt() < other.toInt());
}

bool fixed::operator>= (const fixed& other)
{
	return(this->toInt() >= other.toInt());
}

bool fixed::operator<= (const fixed& other)
{
	return(this->toInt() <= other.toInt());
}

bool fixed::operator== (const fixed& other)
{
	return(this->toInt() == other.toInt());
}

bool fixed::operator!= (const fixed& other)
{
	return(this->toInt() != other.toInt());
}

fixed& fixed::operator+ (const fixed& other)
{
	float value = this->toFloat() + other.toFloat();
	fixed *res = new fixed(value);
	return (*res);
}

fixed& fixed::operator- (const fixed& other)
{
	float value = this->toFloat() - other.toFloat();
	fixed *res = new fixed(value);
	return (*res);
}

fixed& fixed::operator* (const fixed& other)
{
	float value = this->toFloat() * other.toFloat();
	fixed *res = new fixed(value);
	return (*res);
}

fixed& fixed::operator/ (const fixed& other)
{
	float value = this->toFloat() / other.toFloat();
	fixed *res = new fixed(value);
	return (*res);
}

fixed& fixed::operator++ ()
{
	fixed *tmp = new fixed(this->toInt());
	float res = this->toFloat();
	this->_value = toFixed(++res);
	return (*tmp);
}

fixed& fixed::operator++ (int)
{
	float res = this->toFloat();
	this->_value = toFixed(++res);
	return (*this);
}

fixed& fixed::operator-- ()
{
	fixed *tmp = new fixed(this->toInt());
	float res = this->toFloat();
	this->_value = toFixed(--res);
	return (*tmp);
}

fixed& fixed::operator-- (int)
{
	float res = this->toFloat();
	this->_value = toFixed(--res);
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
	float res;
	
	res = (float)this->_value * 1.0;
	res /= 256;

	return (res);
}

int fixed::toInt(void) const
{
	return ((int)this->toFloat());
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
	long temp = nb * 256; //pow(2, this->frac);
	int conv = int(roundf(temp));
	return (conv);
}