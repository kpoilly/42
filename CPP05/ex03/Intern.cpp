/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:01:34 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/27 11:55:54 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){};
Intern::Intern(const Intern& copy){*this = copy;};
const Intern& Intern::operator=(const Intern& copy){(void)copy;return (*this);};
Intern::~Intern(){};

static AForm *CreateShrubbery(std::string target)
{
	AForm *form = new ShrubberyCreationForm(target);
	std::cout << "A New \033[1;32mShrubberyCreationForm\033[0m has been created." << std::endl;
	return (form);
};

static AForm *CreateRobotomy(std::string target)
{
	AForm *form = new RobotomyRequestForm(target);
	std::cout << "A New \033[1;32mRobotomyRequestForm\033[0m has been created." << std::endl;
	return (form);
};

static AForm *CreatePresidential(std::string target)
{
	AForm *form = new PresidentialPardonForm(target);
	std::cout << "A New \033[1;32mPresidentialPardonForm\033[0m has been created." << std::endl;
	return (form);
};

AForm *Intern::makeForm(std::string name, std::string target)
{
	int	pos = -1;
	unsigned long	split = 0;
	std::string formList[3] = {"shrubberycreationform", "robotomyrequestform", "presidentialpardonform"};

	for (unsigned long i = 0; i < name.size(); i++)
		name[i] = std::tolower(name[i]);
	for (unsigned long i = 0; i < 3; i++)
	{
		if (formList[i].find(name) != std::string::npos)
				pos = i;
		else
		{
			split = name.find(" ");
			while (split != std::string::npos)
			{
				if (formList[i].find(name.substr(0, split)) != std::string::npos)
					pos = i;
				name.erase(0, split + 1);
				split = name.find(" ");
			}
		}
	}
		
	switch(pos)
	{
		case -1:
			std::cout << "\033[1;31mCannot create a form named " << name << ".\033[0m" << std::endl;
			break;
		case 0:
			return (CreateShrubbery(target));
		case 1:
			return (CreateRobotomy(target));
		case 2:
			return (CreatePresidential(target));
	}
	return (NULL);
};