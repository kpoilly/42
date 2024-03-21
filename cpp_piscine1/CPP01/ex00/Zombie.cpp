/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:42:39 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/21 12:54:33 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	if (name.empty())
		this->_name = "default";
	else
		this->_name = name;
	this->announce();
}

Zombie::~Zombie()
{
	std::cout<<this->_name<<": died."<<std::endl;
}

void Zombie::announce()
{
	std::cout<<this->_name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}