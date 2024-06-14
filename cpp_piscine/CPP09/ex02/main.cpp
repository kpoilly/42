/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:24:40 by kpoilly           #+#    #+#             */
/*   Updated: 2024/06/14 13:24:39 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	validInput(std::string nb)
{
	for(unsigned long i = 0; i < nb.size(); i++)
	{
		if (!std::isdigit(nb[i]) && nb[i] != ' ')
			return false;
	}
	return true;
}

int	strtoi(std::string str)
{
	int nb;
	std::stringstream ss(str);
	ss >> nb;
	return nb;
}

template<typename T>
T fillCont(char* input)
{
	T cont;
	std::string nb;
	std::stringstream ss(input);

	while(std::getline(ss, nb, ' '))
		cont.push_back(strtoi(nb));
	return cont;
}

int	main(int ac, char**av)
{
	if (ac != 2 || !validInput(av[1]))
	{
		std::cerr << "Error. Invalid input." << std::endl;
		return 42;
	}
	
	std::vector<int> cont1 = fillCont<std::vector<int> >(av[1]);
	std::deque<int> cont2 = fillCont<std::deque<int> >(av[1]);
	
	std::cout << "Before: ";
	for (unsigned long i = 0; i < cont1.size(); i++)
		std::cout << cont1[i] << " ";
	std::cout << std::endl;

	//start chrono
	//merginsSort(cont1);
	//end chrono

	//start chrono
	//merginsSort(cont2);
	//end chrono

	std::cout << "After:  ";
	for (unsigned long i = 0; i < cont1.size(); i++)
		std::cout << cont1[i] << " ";
	std::cout << std::endl;
	
	std::cout << "Time to process a range of " << cont1.size() << " elements";
	std::cout << " with std::" << "vector" << " :  " << 0 << " us" << std::endl;

	std::cout << "Time to process a range of " << cont2.size() << " elements";
	std::cout << " with std::" << "deque" << "  :  " << 0 << " us" << std::endl;
	return 0;
};