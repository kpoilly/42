/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:58:59 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/24 15:38:22 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
AForm("Default", 72, 45){};
RobotomyRequestForm::RobotomyRequestForm(std::string name):
AForm(name, 72, 45){};

//RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)

RobotomyRequestForm::~RobotomyRequestForm(){};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& obj)
{
	os << "\033[1;32m" << obj.getName() << "\033[0m";
	if (obj.isSigned())
		os << ", a signed RobotomyRequestForm by a rank " << obj.getGradeS() << " or greater.";
	else
		os << ", an unsigned RobotomyRequestForm (need to be at rank " << obj.getGradeS() << " or greater).";
	return (os);
}