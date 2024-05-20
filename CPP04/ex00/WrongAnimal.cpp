/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:36:20 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/03 09:06:25 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():_type("WrongAnimal")
{
	std::cout << "\033[1;32mA new WrongAnimal is Born..." << "\033[0m" << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal& copy):_type(copy._type)
{
	std::cout << "\033[1;32mA new WrongAnimal (" << this->_type << ") has been cloned!\033[0m" << std::endl;
};
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy)
{
	this->_type = copy._type;
	std::cout << "\033[1;32mA new WrongAnimal (" << this->_type << ") has been cloned!\033[0m" << std::endl;
	return (*this);
};

WrongAnimal::~WrongAnimal()
{
	std::cout << "\033[1;32mAn WrongAnimal (" << this->_type << ") found a new Home!" << "\033[0m" << std::endl;
};

void WrongAnimal::makeSound() const
{
	std::cout << "\033[1;32mUnReCoGniZaBlE WeIrD wRoNg SoUnD...\033[0m" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->_type);
};
