/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:18:31 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/10 10:53:37 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat Paul("Paul", 42);
	Bureaucrat Boss("Xavier", 1);

	try
	{
		std::cout << Paul << std::endl;
		std::cout << Boss << std::endl;
		std::cout << ++Paul << std::endl;
		std::cout << Paul++ << std::endl;
		std::cout << Paul << std::endl;
		std::cout << Boss++ << std::endl;
		std::cout << Boss << std::endl;
	}
	catch(std::string error)
	{
		std::cerr << error << '\n';
	}
};