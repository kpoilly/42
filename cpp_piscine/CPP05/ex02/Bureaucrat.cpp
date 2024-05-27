/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:18:27 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/27 07:23:16 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade):
	_Name(name), _Grade(grade)
{
	if (this->_Grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_Grade > 150)
		throw Bureaucrat::GradeTooLowException();
};
Bureaucrat::Bureaucrat(const Bureaucrat& copy){*this = copy;};
const Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	this->_Name = copy.getName();
	this->_Grade = copy.getGrade();
	return (*this);
};
Bureaucrat::~Bureaucrat(){};

std::string Bureaucrat::getName() const{return (this->_Name);};
int			Bureaucrat::getGrade() const{return (this->_Grade);};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}

Bureaucrat& Bureaucrat::operator++ (int)
{
	if (this->_Grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	Bureaucrat *tmp = new Bureaucrat(this->_Name, this->_Grade);
	this->_Grade--;
	return (*tmp);
}

Bureaucrat& Bureaucrat::operator++ ()
{
	if (this->_Grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->_Grade--;
	return (*this);
}

Bureaucrat& Bureaucrat::operator-- (int)
{
	if (this->_Grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	Bureaucrat *tmp = new Bureaucrat(this->_Name, this->_Grade);
	this->_Grade++;
	return (*tmp);
}

Bureaucrat& Bureaucrat::operator-- ()
{
	if (this->_Grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->_Grade++;
	return (*this);
}