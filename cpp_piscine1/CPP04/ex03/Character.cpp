/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:59:13 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/07 12:44:55 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): ICharacter(), _Name("Bob"), _invSize(0)
{
	for(int i = 0; i < 4; i++)
		this->_Inventory[i] = nullptr;
};

Character::Character(std::string Name): ICharacter(), _Name(Name), _invSize(0)
{
	for(int i = 0; i < 4; i++)
		this->_Inventory[i] = nullptr;
};

Character::~Character()
{
	for(int i = 0; i < 4; i++)
	{
		if (this->_Inventory[i] != nullptr)
			delete this->_Inventory[i];
		this->_Inventory[i] = nullptr;
	}
};

Character::Character(const Character& copy){*this = copy;};

Character& Character::operator=(const Character& copy)
{
	this->_Name = copy.getName();
	for(int i = 0; i < 4; i++)
	{
		if (this->_Inventory[i] != nullptr)
			delete this->_Inventory[i];
		this->_Inventory[i] = copy._Inventory[i];
	}
	return (*this);
};

void	Character::equip(AMateria* m)
{
	if (this->_invSize >= 4)
		return ;
	
	int	i;
	for (i = 0; this->_Inventory[i] != nullptr; i++);
	this->_Inventory[i] = m;
	this->_invSize++;
};

void	Character::unequip(int idx)
{
	if (idx >= 4)
		return ;
		
	this->_Inventory[idx] = nullptr;
	this->_invSize--;
};

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 4)
		return ;

	std::cout << "* " << this->_Name << " "; 
	this->_Inventory[idx]->use(target);
	std::cout << " at " << target.getName() << " *" << std::endl;
};