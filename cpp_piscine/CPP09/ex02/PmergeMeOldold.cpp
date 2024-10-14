/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:07:51 by kpoilly           #+#    #+#             */
/*   Updated: 2024/06/21 14:09:46 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	Jacobsthal(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return Jacobsthal(n-1) + (2 * Jacobsthal(n-2));
}

bool	sortCondition(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
	return a.second < b.second;
}

bool	sortCondition2(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
	return a.first < b.first;
}

void	merginsSort(std::vector<int>& cont)
{
	//std::cout << "\nVECTOR:\n" << std::endl;
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
	
	//Sort pairs by their greatest value
	std::sort(pairs.begin(), pairs.end(), sortCondition);
	
	bool odd = (cont.size() % 2 == 1);
	int last = cont[cont.size()-1];
	cont.clear();
	
	//Add every "greatests values" to the final sorted list
	for (unsigned long i = 0; i < pairs.size(); i++)
		cont.push_back(pairs[i].second);
	//If the nb of nums is odd, the unpaired element is added to the back
	if (odd)
		pairs.push_back(std::make_pair(last, -1));

	//INSERT
	cont.insert(cont.begin(), pairs[0].first);
	pairs.erase(pairs.begin());
	std::sort(pairs.begin(), pairs.end(), sortCondition2);
	
	for (unsigned long i = 0; i < pairs.size(); i++)
	{
		for (unsigned long j = 0; j < cont.size(); j++)
		{
			//std::cout << pairs[i].first << " <= " << pairs[j].second << " ?" << std::endl;
			if (pairs[i].first <= cont[j])
			{
				cont.insert(std::find(cont.begin(), cont.end(), cont[j]), pairs[i].first);
				break ;
			}
		}
	}

	std::cout << "\nPairs:" << std::endl;
	for (unsigned long i = 0; i < pairs.size(); i++)
		std::cout << pairs[i].first << " | " << pairs[i].second << std::endl;
	std::cout << "sorted:" << std::endl;
	for (unsigned long i = 0; i < cont.size(); i++)
		std::cout << cont[i] << ", ";
	std::cout << std::endl;
};

void	merginsSort(std::list<int>& cont)
{
	//std::cout << "\nLIST:\n" << std::endl;
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
	
	//Sort pairs by their greatest value
	pairs.sort(sortCondition);
	// //If the nb of nums is odd, the unpaired element is added to the back
	// if (cont.size() % 2 == 1)
	// 	pairs.push_back(std::make_pair(-1, cont.back()));
	
	//Add every "greatests values" to the final sorted vector
	cont.clear();
	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
			cont.push_back((*it).second);

	// //INSERT
	// for (unsigned long i = 0; i < pairs.size(); i++)
	// {
	// 	for (unsigned long j = 0; j <= i; j++)
	// 	{
	// 		//std::cout << pairs[i].first << " <= " << pairs[j].second << " ?" << std::endl;
	// 		if (pairs[i].first <= pairs[j].second)
	// 		{
	// 			cont.insert(std::find(cont.begin(), cont.end(),pairs[j].second), pairs[i].first);
	// 			break ;
	// 		}
	// 	}
	// }	
	// std::cout << "Pairs:" << std::endl;
	// for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	// 	std::cout << (*it).first << " | " << (*it).second << std::endl;
	// std::cout << "sorted:" << std::endl;
	// for (std::list<int>::iterator it = cont.begin(); it != cont.end(); it++)
	// 	std::cout << *it << std::endl;
};
