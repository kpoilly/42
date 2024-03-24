/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:12:11 by marvin            #+#    #+#             */
/*   Updated: 2024/03/24 15:12:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():_Name("Bob"){}

ClapTrap::ClapTrap(std::string name):_Name(name)
{
	std::cout << "\033[1;33mClapTrap " << this->_Name << " created.\033[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	this->_EnergyPoints = copy._EnergyPoints;
	this->_HitPoints = copy._HitPoints;
	std::cout << "\033[1;33mClapTrap " << this->_Name << " copied.\033[0m" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "\033[1;33mClapTrap " << this->_Name << " destructed.\033[0m" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_EnergyPoints <= 0)
	{
		std::cout << "\033[1;33mClapTrap " << this->_Name << " doesn't have enough energy to attack !\033[0m" << std::endl;
		return ;
	}
	this->_EnergyPoints--;
	std::cout << "\033[1;33mClapTrap " << this->_Name << " attacks " << target << ", causing " << this->_AttackDmg << " points of damage ! \033[0m" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amout)
{
	if (this->_HitPoints == 0)
	{
		std::cout << "\033[1;33mClapTrap " << this->_Name << " is already dead, it cannot take any more damages.\033[0m" << std::endl;
		return ;
	}
	this->_HitPoints -= amout;
	std::cout << "\033[1;33mClapTrap " << this->_Name << " took " << amout << " damages ! " << this->_HitPoints << " hit points left ! \033[0m" << std::endl;
	if (this->_HitPoints <= 0)
	{
		this->_HitPoints = 0;
		std::cout << "\033[1;33mClapTrap " << this->_Name << " died.\033[0m" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amout)
{
	if (this->_EnergyPoints <= 0)
	{
		std::cout << "\033[1;33mClapTrap " << this->_Name << " doesn't have enough energy to heal !\033[0m" << std::endl;
		return ;
	}
	if (this->_HitPoints == 0)
		std::cout << "\033[1;33mClapTrap " << this->_Name << " is back from the dead !\033[0m" << std::endl;
	this->_HitPoints += amout;
	this->_EnergyPoints--;
	std::cout << "\033[1;33mClapTrap " << this->_Name << " is repairing himself, he now has " << this->_HitPoints << " hit points.\033[0m" << std::endl;
}