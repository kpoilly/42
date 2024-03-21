/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:54:20 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/21 13:00:25 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){};
Harl::~Harl(){};

void Harl::_debug(void)
{
	std::cout << "[DEBUG]: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::_info(void)
{
	std::cout << "[INFO]: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::_warning(void)
{
	std::cout << "[WARNING]: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::_error(void)
{
	std::cout << "[ERROR]: This is unacceptable! I want to speak to the manager now." << std::endl;
}
void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funcs[])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	bool found = false;

	for (int i = 0; i < level.size(); i++)
		level[i] = toupper(level[i]);
	
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*funcs[i])();
			found = true;
		}
	}
	
	if (!found)
		std::cout << "No level matching your complain." << std::endl;
}
void Harl::big_complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	bool found = false;

	for (int i = 0; i < level.size(); i++)
		level[i] = toupper(level[i]);
	
	int i;
	for (i = 0; i < 4 && levels[i] != level; i++);

	switch(i)
	{
		case 0:
			this->_debug();
		case 1:
			this->_info();
		case 2:
			this->_warning();
		case 3:
			this->_error();
			break;
		case 4:
			std::cout << "[" + level + "]: " << "No level matching your complain." << std::endl;
			break;
	}
}