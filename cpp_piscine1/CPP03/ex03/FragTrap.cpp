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

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDmg = 30;
	std::cout << "\033[1;31mFragTrap " << this->_Name << " created.\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDmg = 30;
	this->_Name = name;
	std::cout << "\033[1;31mFragTrap " << this->_Name << " created.\033[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy): ClapTrap(copy)
{
	this->_wfHighFive = copy._wfHighFive;
	std::cout << "\033[1;31mFragTrap " << this->_Name << " copied.\033[0m" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
	this->_Name = copy._Name;
	this->_EnergyPoints = copy._EnergyPoints;
	this->_HitPoints = copy._HitPoints;
	this->_wfHighFive = copy._wfHighFive;
	std::cout << "\033[1;31mFragTrap " << this->_Name << " copied. (via =)\033[0m" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "\033[1;31mFragTrap " << this->_Name << " destructed.\033[0m" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	if (this->_wfHighFive)
	{
		std::cout << "\033[1;31mFragTrap " << this->_Name << " is no longer waiting for an High Five.\033[0m" << std::endl;
		this->_wfHighFive = false;
	}
	else
	{
		std::cout << "\033[1;31mFragTrap " << this->_Name << " is waiting for an High Five !\033[0m" << std::endl;
		this->_wfHighFive = true;

	}
}