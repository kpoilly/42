/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:57:43 by kpoilly           #+#    #+#             */
/*   Updated: 2024/10/11 11:14:24 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int	main(void)
{
	try
	{
		std::vector<int> v(4);
		v.push_back(12);
		v.push_back(42);
		v.push_back(23);
		v.push_back(98);
		
		easyfind(v, 42);
		easyfind(v, 98);
		easyfind(v, 11);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}