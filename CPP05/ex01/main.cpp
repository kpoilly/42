/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:18:31 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/27 09:36:40 by kpoilly          ###   ########.fr       */
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
		//Form		formerr("26B", 0, 1); //Form::GradeTooHighException
		
		std::cout << Paul << std::endl;
		std::cout << Boss << std::endl;
		std::cout << form << std::endl;
		//Paul.signForm(form); //Form::GradeTooLowException
		std::cout << ++Paul << std::endl;
		Paul.signForm(form);
		std::cout << form << std::endl;
		//Boss++; //Bureaucrat::GradeTooHighException
	}
	catch(std::exception &error)
	{
		std::cerr << "\033[1;31m" << error.what() << "\033[0m" << '\n';
	}
};