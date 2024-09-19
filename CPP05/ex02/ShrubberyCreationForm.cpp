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
AForm("ShrubberyCreationForm", 145, 137), _Target("Default"){};
ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
AForm("ShrubberyCreationForm", 145, 137), _Target(target){};

//ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)

ShrubberyCreationForm::~ShrubberyCreationForm(){};

void	ShrubberyCreationForm::execute(const Bureaucrat& executor)
{
	if(!this->isSigned())
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->_GradeX)
		throw AForm::GradeTooLowException();
	
	std::ofstream outfile(&*(this->_Target + "_shrubbery").begin());
	if (!outfile.is_open())
		throw ShrubberyCreationForm::CannotOpenException();
	
	outfile << "							# #### ####\n\
            ### \\/#|### |/####\n\
           ##\\/#/ \\||/##/_/##/_#\n\
         ###  \\/###|/ \\/ # ###\n\
       ##_\\_#\\_\\## | #/###_/_####\n\
      ## #### # \\ #| /  #### ##/##\n\
       __#_--###`  |{,###---###-~\n\
                 \\ }{\n\
                  }}{\n\
                  }}{\n\
                  {{}\n\
            , -=-~{ .-^- _" << std::endl;
	outfile.close();
	std::cout << "\033[1;33m" << this->_Target << "\033[0m now has it's own tree!" << std::endl;
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