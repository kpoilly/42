/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0354/04/08 10:33:33 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/03 09:02:47 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dog.hpp"

Dog::Dog(): Animal()
{
	this->Animal::_type = "Dog";
	std::cout << "\033[1;35mIt's a Dog!\033[0m" << std::endl;
};

Dog::Dog(const Dog& copy)
{
	this->_type = copy._type;
	std::cout << "\033[1;35mIt's a cloned Dog!\033[0m" << std::endl;
};
Dog& Dog::operator=(const Dog& copy)
{
	this->_type = copy._type;
	std::cout << "\033[1;35mIt's a cloned Dog!\033[0m" << std::endl;
	return (*this);
};

Dog::~Dog()
{
	std::cout << "\033[1;35mEnjoy your new family, Dog!\033[0m" << std::endl;
};

void	Dog::makeSound(void) const
{
	std::cout << "\033[1;35mWafWAF! >:D\033[0m" << std::endl;
};
