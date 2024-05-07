/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:03:26 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/07 13:06:33 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Materia.hpp"

AMateria::AMateria(): _Type("Empty"){};
AMateria::AMateria(std::string const & type): _Type(type){};
AMateria::~AMateria(){};

AMateria::AMateria(const AMateria& copy)
{
	*this = copy;
};
AMateria& AMateria::operator =(const AMateria& copy)
{
	this->_Type = copy.getType();
};

std::string const & AMateria::getType() const {return (this->_Type);};

void AMateria::use(ICharacter& target){};
