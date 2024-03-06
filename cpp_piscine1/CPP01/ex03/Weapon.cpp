/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:09:55 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/06 07:50:39 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	if (type.empty())
		this->type = "fists";
	else
		this->type = type;
}

Weapon::~Weapon(){};

void Weapon::setType(std::string type)
{
	this->type = type;
}

const std::string Weapon::getType()
{
	if (this->type.empty())
		this->type = "fists";
	return (this->type);
}