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

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDmg = 20;
	std::cout << "\033[1;32mScavTrap " << this->_Name << " created.\033[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDmg = 20;
	this->_Name = name;
	std::cout << "\033[1;32mScavTrap " << this->_Name << " created.\033[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy): ClapTrap(copy)
{
	this->_gateKeeper = copy._gateKeeper;
	std::cout << "\033[1;32mScavTrap " << this->_Name << " copied.\033[0m" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
	this->_Name = copy._Name;
	this->_EnergyPoints = copy._EnergyPoints;
	this->_HitPoints = copy._HitPoints;
	this->_gateKeeper = copy._gateKeeper;
	std::cout << "\033[1;32mScavTrap " << this->_Name << " copied. (via =)\033[0m" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "\033[1;32mScavTrap " << this->_Name << " destructed.\033[0m" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->_gateKeeper)
	{
		std::cout << "\033[1;32mScavTrap " << this->_Name << " is no longer in gatekeeper mode.\033[0m" << std::endl;
		this->_gateKeeper = false;
	}
	else
	{
		std::cout << "\033[1;32mScavTrap " << this->_Name << " is now in gatekeeper mode.\033[0m" << std::endl;
		this->_gateKeeper = true;

	}
}