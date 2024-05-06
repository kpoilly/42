/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:09:39 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/21 12:57:25 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon_type(weapon)
{
	if (name.empty())
		this->_name = "Bobette";
	else
		this->_name = name;
}

HumanA::~HumanA()
{
	std::cout << this->_name << " died." << std::endl;
}

void HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weapon_type.getType() << "." << std::endl;
}

void HumanA::setWeapon(Weapon& weapon)
{
	this->_weapon_type = weapon;
}
