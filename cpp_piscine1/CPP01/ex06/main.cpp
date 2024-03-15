/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:54:28 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/15 12:53:31 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char** av)
{
	Harl harl;

	std::cout << "\n--------------------------\n" << std::endl;
	harl.big_complain("DEBUG");
	std::cout << "\n--------------------------\n" << std::endl;
	harl.big_complain("INFO");
	std::cout << "\n--------------------------\n" << std::endl;
	harl.big_complain("WARNING");
	std::cout << "\n--------------------------\n" << std::endl;
	harl.big_complain("ERROR");
	std::cout << "\n--------------------------\n" << std::endl;
	harl.big_complain("NOPE");
	
}
