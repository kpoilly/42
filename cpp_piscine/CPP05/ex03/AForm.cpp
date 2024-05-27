/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:58:59 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/24 15:38:22 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, int grades, int gradex):
_Name(name), _Signed(false), _GradeS(grades), _GradeX(gradex)
{
	if (this->_GradeS < 1 || this->_GradeX < 1)
		throw AForm::GradeTooHighException();
	if (this->_GradeS > 150 || this->_GradeX > 150)
		throw AForm::GradeTooLowException();
};

AForm::AForm(const AForm& copy):
_Name(copy.getName()), _Signed(copy.isSigned()), _GradeS(copy.getGradeS()), _GradeX(copy.getGradeX()){}; 

AForm::~AForm(){};

std::string 	AForm::getName() const
{return(this->_Name);};
bool				AForm::isSigned() const
{return(this->_Signed);};
int 			AForm::getGradeS() const
{return(this->_GradeS);};
int 			AForm::getGradeX() const
{return(this->_GradeX);};

void		AForm::beSigned(const Bureaucrat& signer)
{
	if(signer.getGrade() > this->_GradeS)
		throw AForm::GradeTooLowException();
	this->_Signed = true;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
	os << "\033[1;32m" << obj.getName() << "\033[0m";
	if (obj.isSigned())
		os << ", a signed Aform by a rank " << obj.getGradeS() << " or greater.";
	else
		os << ", an unsigned Aform (need to be at rank " << obj.getGradeS() << " or greater).";
	return (os);
}