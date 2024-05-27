/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:18:31 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/27 10:53:42 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat 	Boss("Xavier", 1);
		Bureaucrat 	Employee("Paul", 149);
		
		ShrubberyCreationForm  Shrub("Jack");
		RobotomyRequestForm	   Robot("Bob");
		PresidentialPardonForm Pres("Jerry");

		std::cout << Boss << std::endl;
		
		std::cout << "\n";\
		//Employee.signForm(Robot); //AForm::GradeTooLow
		Boss.signForm(Robot);
		Employee.executeForm(Robot);
		Boss.executeForm(Robot);
		Boss.executeForm(Robot);
		Boss.executeForm(Robot);
		Boss.executeForm(Robot);

		std::cout << "\n";
		Boss.signForm(Shrub);
		Boss.executeForm(Shrub);

		std::cout << "\n";
		Boss.executeForm(Pres);
		Boss.signForm(Pres);
		Boss.executeForm(Pres);
	}
	catch(std::exception &error)
	{
		std::cerr << "\033[1;31m" << error.what() << "\033[0m" << '\n';
	}
};