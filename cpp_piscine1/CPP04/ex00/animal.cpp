/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:36:20 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/03 08:53:01 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"

Animal::Animal():_type("Animal")
{
	std::cout << "\033[1;31mA new animal is Born..." << "\033[0m" << std::endl;
};

Animal::Animal(const Animal& copy):_type(copy._type)
{
	std::cout << "\033[1;31mA new animal (" << this->_type << ") has been cloned!\033[0m" << std::endl;
};
Animal& Animal::operator=(const Animal& copy)
{
	this->_type = copy._type;
	std::cout << "\033[1;31mA new animal (" << this->_type << ") has been cloned!\033[0m" << std::endl;
	return (*this);
};

Animal::~Animal()
{
	std::cout << "\033[1;31mAn animal (" << this->_type << ") found a new Home!" << "\033[0m" << std::endl;
};

void Animal::makeSound() const
{
	if (this->_type == "Cat")
		std::cout << "\033[1;33mMeeeeeooooow >:3\033[0m" << std::endl;
	else if (this->_type == "Dog")
		std::cout << "\033[1;35mWafWAF! >:D\033[0m" << std::endl;
	else if (this->_type == "Frog")
		std::cout << "\033[1;32mCrooooOOAAAAAaaa! <3\033[0m" << std::endl;
	else
		std::cout << "\033[1;31mUnReCoGniZaBlE WeIrD SoUnD...\033[0m" << std::endl;
}

std::string Animal::getType() const
{
	return (this->_type);
};
