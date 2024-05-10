/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:18:31 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/10 12:37:36 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat 	Paul("Paul", 42);
	Bureaucrat 	Boss("Xavier", 1);
	Form		form("26B", 41, 1);

	try
	{
		std::cout << Paul << std::endl;
		std::cout << Boss << std::endl;
		Paul.signForm(form); //Form::GradeTooLowException
		std::cout << Paul++ << std::endl;
		Paul.signForm(form);
		Boss++; //Bureaucrat::GradeTooHighException
	}
	catch(std::string error)
	{
		std::cerr << "\033[1;31m" + error  + "\033[0m" << '\n';
	}
};