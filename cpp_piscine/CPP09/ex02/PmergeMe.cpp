/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:07:51 by kpoilly           #+#    #+#             */
/*   Updated: 2024/06/17 14:50:59 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	sortCondition(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
	return a.first < b.first;
}

void	merginsSort(std::vector<int>& cont)
{
	std::cout << "\nVECTOR:\n" << std::endl;
	//MERGE
	//Make Pairs
	std::vector<std::pair<int, int> > pairs;
	for (unsigned long i = 0; i < cont.size()-1; i+=2)
	{
		if (cont[i] < cont[i+1])
			pairs.push_back(std::make_pair(cont[i], cont[i+1]));
		else
			pairs.push_back(std::make_pair(cont[i+1], cont[i]));
	}
	
	//Sort pairs by a
	std::sort(pairs.begin(), pairs.end(), sortCondition);
	//If the nb of nums is odd, the unpaired element is added to the back
	if (cont.size() % 2 == 1)
		pairs.push_back(std::make_pair(-1, cont[cont.size()-1]));
	
	//Add every a to the final sorted vector
	cont.clear();
	for (unsigned long i = 0; i < pairs.size(); i++)
		if (pairs[i].first >= 0)
			cont.push_back(pairs[i].first);

	std::cout << "Pairs:" << std::endl;
	for (unsigned long i = 0; i < pairs.size(); i++)
		std::cout << i << ": " << pairs[i].first << " | " << pairs[i].second << std::endl;
	std::cout << "sorted:" << std::endl;
	for (unsigned long i = 0; i < cont.size(); i++)
		std::cout << i << ": " << cont[i] << std::endl;

	//INSERT
	
};

void	merginsSort(std::list<int>& cont)
{
	std::cout << "\nLIST:\n" << std::endl;
	//MERGE
	//Make Pairs
	std::list<std::pair<int, int> > pairs;
	while(cont.size() > 1)
	{
		pairs.push_back(std::make_pair(cont.front(), cont.front()));
		cont.pop_front();
		if (cont.front() > pairs.back().first)
			pairs.back().second = cont.front();
		else
			pairs.back().first = cont.front();
		cont.pop_front();
	}
	
	//Sort pairs by a
	pairs.sort(sortCondition);
	//If the nb of nums is odd, the unpaired element is added to the back
	if (cont.size() % 2 == 1)
		pairs.push_back(std::make_pair(-1, cont.back()));
	
	//Add every a to the final sorted vector
	cont.clear();
	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
		if ((*it).first >= 0)
			cont.push_back((*it).first);

	std::cout << "Pairs:" << std::endl;
	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
		std::cout << (*it).first << " | " << (*it).second << std::endl;
	std::cout << "sorted:" << std::endl;
	for (std::list<int>::iterator it = cont.begin(); it != cont.end(); it++)
		std::cout << *it << std::endl;

	//INSERT
};