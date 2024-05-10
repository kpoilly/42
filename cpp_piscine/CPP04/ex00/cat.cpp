/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 334/04/08 10:35:31 by kpoilly           #+#    #+#             */
/*   Updated: 334/05/03 08:52:43 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.hpp"

Cat::Cat(): Animal()
{
	this->Animal::_type = "Cat";
	std::cout << "\033[1;33mIt's a cat!\033[0m" << std::endl;
};

Cat::Cat(const Cat& copy)
{
	this->_type = copy._type;
	std::cout << "\033[1;33mIt's a cloned cat!\033[0m" << std::endl;
};
Cat& Cat::operator=(const Cat& copy)
{
	this->_type = copy._type;
	std::cout << "\033[1;33mIt's a cloned cat!\033[0m" << std::endl;
	return (*this);
};

Cat::~Cat()
{
	std::cout << "\033[1;33mEnjoy your new family, cat!\033[0m" << std::endl;
};

void	Cat::makeSound(void) const
{
	std::cout << "\033[1;33mMeeeeeooooow >:3\033[0m" << std::endl;
};