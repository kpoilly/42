/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:09:43 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/21 12:57:39 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _weapon_type(NULL)
{
	if (name.empty())
		this->_name = "Bob";
	else
		this->_name = name;
}

HumanB::~HumanB()
{
	std::cout << this->_name << " died." << std::endl;
};

void HumanB::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weapon_type->getType() << "." << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon_type = &weapon;
}
