/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:30:36 by kpoilly           #+#    #+#             */
/*   Updated: 2024/06/06 18:24:01 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		std::cerr << "Error: not input file given." << std::endl;
		return 42;
	}
	std::map<std::string, long double> data = get_data();
	if (data.empty())
		return 42;
	read_input(av[1], data);
	// for(std::map<std::string, long double>::iterator i = data.begin(); i != data.end(); i++)
	// 	std::cout << i->first << " | " << i->second << "\n";
};