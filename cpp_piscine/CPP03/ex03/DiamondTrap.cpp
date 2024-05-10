/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:36:30 by marvin            #+#    #+#             */
/*   Updated: 2024/03/24 16:36:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): FragTrap("Bob"), ScavTrap("Bob")
{
	this->_Name = "Bob";
	this->ClapTrap::_Name = "Bob_clap_name";
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDmg = 30;

	std::cout << "\033[1;36mDiamondTrap " << this->_Name << " created. (default)\033[0m" << std::endl;
};

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	this->_Name = name;
	this->ClapTrap::_Name = name + "_clap_name";
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDmg = 30;

	std::cout << "\033[1;36mDiamondTrap " << this->_Name << " created.\033[0m" << std::endl;
};

DiamondTrap::DiamondTrap(const DiamondTrap& copy)
{
	this->_Name = copy._Name;
	this->ClapTrap::_Name = copy.ClapTrap::_Name;
	this->_HitPoints = copy._HitPoints;
	this->_EnergyPoints = copy._EnergyPoints;
	this->_AttackDmg = copy._AttackDmg;

	std::cout << "\033[1;36mDiamondTrap " << this->_Name << " copied.\033[0m" << std::endl;
};

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy)
{
	this->_Name = copy._Name;
	this->ClapTrap::_Name = copy.ClapTrap::_Name;
	this->_HitPoints = copy._HitPoints;
	this->_EnergyPoints = copy._EnergyPoints;
	this->_AttackDmg = copy._AttackDmg;

	std::cout << "\033[1;36mDiamondTrap " << this->_Name << " copied. (via =)\033[0m" << std::endl;
	return (*this);
};

DiamondTrap::~DiamondTrap()
{
	std::cout << "\033[1;36mDiamondTrap " << this->_Name << " destructed.\033[0m" << std::endl;
};

void	DiamondTrap::whoAmI() const
{
	std::cout << "\033[1;36mDiamondTrap name: " << this->_Name;
	std::cout << ", ClapTrap name: " << this->ClapTrap::_Name << "\033[0m" << std::endl;
};