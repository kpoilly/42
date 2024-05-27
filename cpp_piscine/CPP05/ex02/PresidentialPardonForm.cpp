/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:58:59 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/24 15:38:22 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
AForm("Default", 25, 5){};
PresidentialPardonForm::PresidentialPardonForm(std::string name):
AForm(name, 25, 5){};

//PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)

PresidentialPardonForm::~PresidentialPardonForm(){};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& obj)
{
	os << "\033[1;32m" << obj.getName() << "\033[0m";
	if (obj.isSigned())
		os << ", a signed PresidentialPardonForm by a rank " << obj.getGradeS() << " or greater.";
	else
		os << ", an unsigned PresidentialPardonForm (need to be at rank " << obj.getGradeS() << " or greater).";
	return (os);
}