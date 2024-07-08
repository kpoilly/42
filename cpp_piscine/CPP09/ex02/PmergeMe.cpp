/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:07:51 by kpoilly           #+#    #+#             */
/*   Updated: 2024/07/08 16:39:38 by kpoilly          ###   ########.fr       */
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

	while (!left.empty())
	{
		merged.push_back(left.front());
		left.pop_front();
	}
	while (!right.empty())
	{
		merged.push_back(right.front());
		right.pop_front();
	}
	
	return merged;
}

std::list<int>	merginsSortList(std::list<int>& cont)
{
	//std::cout << "\nLIST:\n" << std::endl;
	if (cont.size() <= 1)
		return cont;
	
	std::list<int>::iterator mid = cont.begin();
	std::advance(mid, cont.size() /2);

	std::list<int> left(cont.begin(), mid);
	std::list<int> right(mid, cont.end());

	left = merginsSortList(left);
	right = merginsSortList(right);

	return mergList(left, right);
};
