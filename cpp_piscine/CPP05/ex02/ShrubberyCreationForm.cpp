/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:58:59 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/24 15:38:22 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
AForm("Default", 145, 137){};
ShrubberyCreationForm::ShrubberyCreationForm(std::string name):
AForm(name, 145, 137){};

//ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)

ShrubberyCreationForm::~ShrubberyCreationForm(){};

void	ShrubberyCreationForm::execute(const Bureaucrat& executor)
{
	if(executor.getGrade() > this->_GradeX)
		throw AForm::GradeTooLowException();
	
	
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& obj)
{
	os << "\033[1;32m" << obj.getName() << "\033[0m";
	if (obj.isSigned())
		os << ", a signed ShrubberyCreationForm by a rank " << obj.getGradeS() << " or greater.";
	else
		os << ", an unsigned ShrubberyCreationForm (need to be at rank " << obj.getGradeS() << " or greater).";
	return (os);
}