/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:09:43 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/06 09:02:47 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : weapon_type(NULL)
{
	if (name.empty())
		this->name = "Pouet";
	else
		this->name = name;
}

HumanB::~HumanB()
{
	std::cout << this->name << " died." << std::endl;
};

void HumanB::attack()
{
	std::cout << this->name << " attacks with their " << this->weapon_type->getType() << "." << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon_type = &weapon;
}
