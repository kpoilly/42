/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:18:31 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/27 08:50:14 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat Paul("Paul", 42);
		Bureaucrat Boss("Xavier", 1);
		//Bureaucrat Bobby("Bobby", 167); //Bureaucrat::GradeTooLowException

		std::cout << Paul << std::endl;
		std::cout << Boss << std::endl;
		std::cout << ++Paul << std::endl;
		std::cout << Paul++ << std::endl;
		std::cout << Paul << std::endl;
		std::cout << --Paul << std::endl;
		//std::cout << Boss++ << std::endl; //Bureaucrat::GradeTooHighException
		std::cout << Boss << std::endl;
	}
	catch(std::exception &error)
	{
		std::cerr << "\033[1;31m" << error.what() << "\033[0m" << '\n';
	}
};