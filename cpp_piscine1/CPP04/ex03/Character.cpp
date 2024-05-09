/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:59:13 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/09 10:55:23 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): ICharacter(), _Name("Bob"), _invSize(0)
{
	for(int i = 0; i < 4; i++)
		this->_Inventory[i] = NULL;
};

Character::Character(std::string Name): ICharacter(), _Name(Name), _invSize(0)
{
	for(int i = 0; i < 4; i++)
		this->_Inventory[i] = NULL;
};

Character::~Character()
{
	for(int i = 0; i < 4; i++)
	{
		if (this->_Inventory[i] != NULL)
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
	
	this->_invSize = 0;
	for(int i = 0; i < 4; i++)
		if (this->_Inventory[i] != NULL)
			this->_invSize++;
	return (*this);
};

std::string const & Character::getName() const
{
	return (this->_Name);
};

void	Character::equip(AMateria* m)
{
	if (this->_invSize >= 4)
		return ;
	
	this->_Inventory[this->_invSize] = m;
	this->_invSize++;
};

void	Character::unequip(int idx)
{
	if (idx >= 4)
		return ;
	
	this->_Inventory[idx] = NULL;
	this->_invSize--;
};

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 4 || this->_Inventory[idx] == NULL)
		return ;
	std::cout << "* \033[1;34m" << this->_Name << "\033[0m ";
	this->_Inventory[idx]->use(target);
};