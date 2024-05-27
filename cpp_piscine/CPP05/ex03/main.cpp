/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:18:31 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/27 11:58:43 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
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
		Intern someRandomIntern;
		AForm* rrf;
		
		std::cout << "\n";
		rrf = someRandomIntern.makeForm("robotomy request", "Bob");
		if (rrf == NULL)
			return (1);
		std::cout << "\n";
		Boss.signForm(*rrf);
		Boss.executeForm(*rrf);

		std::cout << "\n";
		rrf = someRandomIntern.makeForm("Brand New Shrubbery !", "Jack");
		if (rrf == NULL)
			return (1);
		std::cout << "\n";
		Boss.signForm(*rrf);
		Boss.executeForm(*rrf);

		std::cout << "\n";
		rrf = someRandomIntern.makeForm("I President, I give PARDON", "Eric");
		if (rrf == NULL)
			return (1);
		std::cout << "\n";
		Boss.signForm(*rrf);
		Boss.executeForm(*rrf);
	}
	catch(std::exception &error)
	{
		std::cerr << "\033[1;31m" << error.what() << "\033[0m" << '\n';
	}
};