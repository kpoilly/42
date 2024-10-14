/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 07:24:40 by kpoilly           #+#    #+#             */
/*   Updated: 2024/10/14 13:27:21 by kpoilly          ###   ########.fr       */
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
T fillCont(std::string input)
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
	std::string input;
	
	if (ac > 2)
	{
		for (int i = 1; i < ac; i++)
		{
			input += av[i];
			input += " ";
		}
	}
	else if (ac == 2)
		input = av[1];
	else
		return (42);
	if (!validInput(input))
	{
		std::cerr << "Error. Invalid input." << std::endl;
		return 42;
	}
	
	std::cout << "\033[4;33mBefore : " << input << "\033[0m" << std::endl;

	struct timeval tv1, tv2;
	gettimeofday(&tv1, NULL);
	std::vector<int> cont1 = fillCont<std::vector<int> >(input);
	std::cout << "\033[1;30m\nsorting vector...\033[1;32m" << std::endl;
	sort(cont1);
	gettimeofday(&tv2, NULL);
	double time1 = (double) (tv2.tv_sec - tv1.tv_sec);
	time1 = (double) ((time1 * 1000000) + (tv2.tv_usec - tv1.tv_usec));
	
	std::cout << "\033[1;32mAfter (\033[1;31mstd::vector\033[1;32m) :  \033[1;33m";
	for (unsigned long i = 0; i < cont1.size(); i++)
		std::cout << cont1[i] << " ";
	std::cout << std::endl;

	gettimeofday(&tv1, NULL);
	std::deque<int> cont2 = fillCont<std::deque<int> >(input);
	std::cout << "\033[1;30m\nsorting deque...\033[1;32m" << std::endl;
	sort(cont2);
	gettimeofday(&tv2, NULL);
	double time2 = (double) (tv2.tv_sec - tv1.tv_sec);
	time2 = (double) ((time2 * 1000000) + (tv2.tv_usec - tv1.tv_usec));

	std::cout << "\033[1;32mAfter (\033[1;31mstd::list\033[1;32m)   :  \033[1;33m";
	std::deque<int>::iterator it = cont2.begin();
	for (unsigned long i = 0; i < cont2.size(); i++)
		std::cout << *(it++) << " ";
	std::cout << std::endl;

	std::cout << "\033[1;32m\nTime to process a range of " << cont1.size() << " elements";
	std::cout << " with std::vector :  \033[1;33m" << time1 << "\033[1;32m us" << std::endl;
	std::cout << "\033[1;32mTime to process a range of " << cont2.size() << " elements";
	std::cout << " with std::deque   :  \033[1;33m" << time2 << "\033[1;32m us\033[0m" << std::endl;

	return 0;
};