/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:07:51 by kpoilly           #+#    #+#             */
/*   Updated: 2024/07/02 15:34:52 by kpoilly          ###   ########.fr       */
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

std::vector<int>	mergVec(std::vector<int>& left, std::vector<int>& right)
{
	std::vector<int> merged;

	while (!left.empty() && !right.empty())
	{
		if (right.front() <= left.front())
		{
			merged.push_back(right.front());
			right.erase(right.begin());
		}
		else
		{
			merged.push_back(left.front());
			left.erase(left.begin());
		}
	}
	
	for(long double i = 0; i < left.size(); i++)
		merged.push_back(left[i]);
	for(long double i = 0; i < right.size(); i++)
		merged.push_back(right[i]);

	return merged;
}

std::vector<int>	merginsSortVec(std::vector<int>& cont)
{
	//std::cout << "\nVECTOR:\n" << std::endl;
	if (cont.size() <= 1)
		return cont;
	long double	size = cont.size() /2;
	
	std::vector<int> left(cont.begin(), cont.begin() + size);
	std::vector<int> right(cont.begin() + size, cont.end());

	left = merginsSortVec(left);
	right = merginsSortVec(right);

	return mergVec(left, right);
};

std::list<int>	mergList(std::list<int>& left, std::list<int>& right)
{
	std::list<int> merged;

	while (!left.empty() && !right.empty())
	{
		if (right.front() <= left.front())
		{
			merged.push_back(right.front());
			right.pop_front();
		}
		else
		{
			merged.push_back(left.front());
			left.pop_front();
		}
	}
	
	for(long double i = 0; i < left.size(); i++)
		merged.push_back(left.front());
	for(long double i = 0; i < right.size(); i++)
		merged.push_back(right.front());
	
	return merged;
}

std::list<int>	merginsSortList(std::list<int>& cont)
{
	//std::cout << "\nLIST:\n" << std::endl;
	if (cont.size() <= 1)
		return cont;
	long double	size = cont.size() /2;
	
	std::list<int> left;
	std::list<int> right;

	for (long double i = 0; i < size; i++)
	{
		left.push_back(cont.front());
		cont.pop_front();
	}
	//size = cont.size();
	for (long double i = 0; cont.size(); i++)
	{
		right.push_back(cont.front());
		cont.pop_front();
	}

	left = merginsSortList(left);
	right = merginsSortList(right);

	return mergList(left, right);
};
