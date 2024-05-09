/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 08:23:17 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/09 09:58:23 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria()
{
	_Type = "cure";
};

Cure::Cure(const Cure& copy)
{
	*this = copy;
};

const Cure& Cure::operator=(const Cure& copy)
{
	return (*(copy.clone()));
};

Cure::~Cure(){};

void Cure::use(ICharacter& target)
{
	std::cout << "\033[1;32mheals \033[0m";
	std::cout << "\033[1;31m" << target.getName() << "\033[0m's wounds *" << std::endl;
};

Cure* Cure::clone() const
{
	Cure *copy = new Cure();
	copy = (Cure *)this;
	return (copy);
};