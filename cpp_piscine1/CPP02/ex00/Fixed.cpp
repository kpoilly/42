/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:52:27 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/15 13:24:28 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

fixed::fixed()
{
	std::cout << "Default Constructor called." <<std::endl;
	this->value = 0;
}
fixed::fixed(fixed& nb)
{
	std::cout << "Copy Constructor called." <<std::endl;
	this->value = nb.value;
}
fixed::~fixed()
{
	std::cout << "Destructor called." <<std::endl;
}

fixed& fixed::operator=(fixed& nb)
{
	std::cout << "Copy assignement operator called (=)." <<std::endl;
	this->value = nb.value;
	return (*this);
}

const int fixed::getRawBits(void)
{
	std::cout << "getRawBits member called :" << std::endl;
	return (this->value);
}
void fixed::setRawBits(int const raw)
{
	std::cout << "getRawBits member called." << std::endl;
	this->value = raw;
}
