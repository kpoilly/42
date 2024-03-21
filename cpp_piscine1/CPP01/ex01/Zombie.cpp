/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:42:39 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/21 12:56:13 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie():_name("Bob"){};

Zombie::Zombie(std::string name)
{
	if (name.empty())
		this->_name = "Bob";
	else
		this->_name = name;
}

Zombie::~Zombie()
{
	std::cout << this->_name << ": died." << std::endl;
}

void Zombie::set_name(std::string name)
{
	this->_name = name;
}

void Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}