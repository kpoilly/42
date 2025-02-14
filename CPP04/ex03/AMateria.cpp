/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:03:26 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/09 12:47:37 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(): _Type("Empty"), equipped(false){};
AMateria::AMateria(std::string const & type): _Type(type), equipped(false){};
AMateria::~AMateria(){};

AMateria::AMateria(const AMateria& copy)
{
	*this = copy;
};
AMateria& AMateria::operator =(const AMateria& copy)
{
	this->_Type = copy.getType();
	return (*this);
};

std::string const & AMateria::getType() const {return (this->_Type);};

AMateria* AMateria::clone() const
{
	return((AMateria *)this);
};

void AMateria::use(ICharacter& target)
{
	std::cout << "A Materia has been used on " << target.getName() << std::endl;
};
