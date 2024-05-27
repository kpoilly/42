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

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, int grades, int gradex):
AForm(name, grades, gradex){};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy):
_Name(copy.getName()), _Signed(copy.isSigned()), _GradeS(copy.getGradeS()), _GradeX(copy.getGradeX()){}; 

ShrubberyCreationForm::~ShrubberyCreationForm(){};

std::string 	ShrubberyCreationForm::getName() const
{return(this->_Name);};
bool				ShrubberyCreationForm::isSigned() const
{return(this->_Signed);};
int 			ShrubberyCreationForm::getGradeS() const
{return(this->_GradeS);};
int 			ShrubberyCreationForm::getGradeX() const
{return(this->_GradeX);};

void		ShrubberyCreationForm::beSigned(const Bureaucrat& signer)
{
	if(signer.getGrade() > this->_GradeS)
		throw std::string("ShrubberyCreationForm::GradeTooLowException");
	this->_Signed = true;
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& obj)
{
	os << "\033[1;32m" << obj.getName() << "\033[0m";
	if (obj.isSigned())
		os << ", a signed ShrubberyCreationForm by a rank " << obj.getGradeS() << " or greater.";
	else
		os << ", an unsigned ShrubberyCreationForm (need to be at rank " << obj.getGradeS() << " or greater).";
	return (os);
}