/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:59:13 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/09 13:13:50 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): ICharacter(), _Name("Bob")
{
	for(int i = 0; i < 4; i++)
		this->_Inventory[i] = NULL;
};

Character::Character(std::string Name): ICharacter(), _Name(Name)
{
	for(int i = 0; i < 4; i++)
		this->_Inventory[i] = NULL;
};

Character::~Character()
{
	for(int i = 0; i < 4; i++)
		if (this->_Inventory[i])
		{
			delete this->_Inventory[i];
			this->_Inventory[i] = NULL;
		}
};

Character::Character(const Character& copy){*this = copy;};

Character& Character::operator=(const Character& copy)
{
	this->_Name = copy.getName();
	for(int i = 0; i < 4; i++)
	{
		if (this->_Inventory[i])
			delete this->_Inventory[i];
		this->_Inventory[i] = copy._Inventory[i];
	}
	return (*this);
};

std::string const & Character::getName() const
{
	return (this->_Name);
};

void	Character::equip(AMateria* m)
{
	if (m->equipped)
	{
		std::cout << "This Materia has already been equipped !" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!this->_Inventory[i])
		{
			this->_Inventory[i] = m;
			m->equipped = true;
			std::cout << "\033[1;34m" << this->_Name << " \033[0m";
			std::cout << "added \033[1;35m" << m->getType() << "\033[0m";
			std::cout << " to his inventory." << std::endl;
			return ;
		}
	}
};

void	Character::unequip(int idx)
{
	if (idx >= 4 || idx < 0 || !this->_Inventory[idx])
		return ;
	
	std::cout << "\033[1;34m" << this->_Name << " \033[0m";
	std::cout << "removed \033[1;35m" << this->_Inventory[idx]->getType() << "\033[0m";
	std::cout << " from his inventory." << std::endl;
	this->_Inventory[idx] = NULL;
};

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 4 || idx < 0 || this->_Inventory[idx] == NULL)
		return ;
	std::cout << "* \033[1;34m" << this->_Name << "\033[0m ";
	this->_Inventory[idx]->use(target);
};