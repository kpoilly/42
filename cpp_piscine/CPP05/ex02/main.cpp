/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:18:31 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/27 08:44:30 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		Bureaucrat 	Paul("Paul", 42);
		Bureaucrat 	Boss("Xavier", 1);
		Form		form("26B", 41, 1);

		std::cout << Paul << std::endl;
		std::cout << Boss << std::endl;
		std::cout << form << std::endl;
		Paul.signForm(form); //Form::GradeTooLowException
		std::cout << ++Paul << std::endl;
		Paul.signForm(form);
		std::cout << form << std::endl;
		Boss++; //Bureaucrat::GradeTooHighException
	}
	catch(std::string error)
	{
		std::cerr << "\033[1;31m" + error  + "\033[0m" << '\n';
	}
};