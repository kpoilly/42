/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:09:55 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/21 12:58:03 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	if (type.empty())
		this->_type = "fists";
	else
		this->_type = type;
}

Weapon::~Weapon(){};

void Weapon::setType(std::string type)
{
	this->_type = type;
}

const std::string Weapon::getType()
{
	if (this->_type.empty())
		this->_type = "fists";
	return (this->_type);
}