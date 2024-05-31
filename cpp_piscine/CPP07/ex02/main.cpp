/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 08:46:07 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/31 10:19:33 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	try
	{
		Array<int> iArray(5);
		iArray[1] = 42;
		std::cout << iArray[1] << std::endl;
		std::cout << iArray[3] << std::endl;

		Array<std::string> sArray(5);
		sArray[1] = "Coucou";
		std::cout << sArray[1] << std::endl;
		std::cout << sArray[14] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}