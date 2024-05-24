/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:58:59 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/24 15:38:22 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int grades, int gradex):
_Name(name), _Signed(false), _GradeS(grades), _GradeX(gradex){};

Form::Form(const Form& copy):
_Name(copy.getName()), _Signed(copy.isSigned()), _GradeS(copy.getGradeS()), _GradeX(copy.getGradeX()){}; 

Form::~Form(){};

std::string 	Form::getName() const
{return(this->_Name);};
bool				Form::isSigned() const
{return(this->_Signed);};
int 			Form::getGradeS() const
{return(this->_GradeS);};
int 			Form::getGradeX() const
{return(this->_GradeX);};

void		Form::beSigned(const Bureaucrat& signer)
{
	if(signer.getGrade() > this->_GradeS)
		throw std::string("Form::GradeTooLowException");
	this->_Signed = true;
};

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	os << "\033[1;32m" << obj.getName() << "\033[0m";
	if (obj.isSigned())
		os << ", a signed form by a rank " << obj.getGradeS() << " or greater.";
	else
		os << ", an unsigned form (need to be at rank " << obj.getGradeS() << " or greater).";
	return (os);
}