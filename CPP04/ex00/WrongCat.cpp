/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 334/04/08 10:35:31 by kpoilly           #+#    #+#             */
/*   Updated: 334/05/03 08:52:43 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	this->WrongAnimal::_type = "WrongCat";
	std::cout << "\033[1;36mIt's a WrongCat!\033[0m" << std::endl;
};

WrongCat::WrongCat(const WrongCat& copy)
{
	this->_type = copy._type;
	std::cout << "\033[1;36mIt's a cloned WrongCat!\033[0m" << std::endl;
};
WrongCat& WrongCat::operator=(const WrongCat& copy)
{
	this->_type = copy._type;
	std::cout << "\033[1;36mIt's a cloned WrongCat!\033[0m" << std::endl;
	return (*this);
};

WrongCat::~WrongCat()
{
	std::cout << "\033[1;36mEnjoy your new family, WrongCat!\033[0m" << std::endl;
};

void	WrongCat::makeSound(void) const
{
	std::cout << "\033[1;36mblblblblblblbl >:3\033[0m" << std::endl;
};