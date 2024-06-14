/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:24:40 by kpoilly           #+#    #+#             */
/*   Updated: 2024/06/14 13:42:39 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <unistd.h>

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

	struct timeval tv1, tv2;
	gettimeofday(&tv1, NULL);
	//merginsSort(cont1);
	gettimeofday(&tv2, NULL);
	double time1 = (double) (tv2.tv_usec - tv1.tv_usec);

	gettimeofday(&tv1, NULL);
	//merginsSort(cont2);
	gettimeofday(&tv2, NULL);
	double time2 = (double) (tv2.tv_usec - tv1.tv_usec);

	std::cout << "After:  ";
	for (unsigned long i = 0; i < cont1.size(); i++)
		std::cout << cont1[i] << " ";
	std::cout << std::endl;
	
	std::cout << "Time to process a range of " << cont1.size() << " elements";
	std::cout << " with std::" << "vector" << " :  " << time1 << " us" << std::endl;

	std::cout << "Time to process a range of " << cont2.size() << " elements";
	std::cout << " with std::" << "deque" << "  :  " << time2 << " us" << std::endl;
	return 0;
};