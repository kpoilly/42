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
AForm("RobotomyRequestForm", 72, 45), _Target("Default"){};
RobotomyRequestForm::RobotomyRequestForm(std::string target):
AForm("RobotomyRequestForm", 72, 45), _Target(target){};

//RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)

RobotomyRequestForm::~RobotomyRequestForm(){};

void	RobotomyRequestForm::execute(const Bureaucrat& executor)
{
	if(!this->isSigned())
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->_GradeX)
		throw AForm::GradeTooLowException();
	
	
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& obj)
{
	os << "\033[1;32m" << obj.getName() << "\033[0m";
	if (obj.isSigned())
		os << ", a signed RobotomyRequestForm by a rank " << obj.getGradeS() << " or greater.";
	else
		os << ", an unsigned RobotomyRequestForm (need to be at rank " << obj.getGradeS() << " or greater).";
	return (os);
}