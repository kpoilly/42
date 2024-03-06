/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:09:39 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/06 09:03:25 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : weapon_type(weapon)
{
	if (name.empty())
		this->name = "Pouet";
	else
		this->name = name;
}

HumanA::~HumanA()
{
	std::cout << this->name << " died." << std::endl;
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon_type.getType() << "." << std::endl;
}

void HumanA::setWeapon(Weapon& weapon)
{
	this->weapon_type = weapon;
}
