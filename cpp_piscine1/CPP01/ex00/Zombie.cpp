/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:42:39 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/05 11:09:20 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	if (name.empty())
		this->name = "default";
	else
		this->name = name;
	this->announce();
}

Zombie::~Zombie()
{
	std::cout<<this->name<<": died."<<std::endl;
}

void Zombie::announce()
{
	std::cout<<this->name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}