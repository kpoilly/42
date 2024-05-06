/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:52:10 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/06 12:42:50 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	{
	fixed a;
	fixed const b(fixed(5.05f) * fixed(2));

	std::cout << "a : " << a << std::endl;
	std::cout << "++a : " << ++a << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "a++ : " << a++ << std::endl;
	std::cout << "a : " << a << std::endl;

	std::cout << "b : " << b << std::endl;
	
	std::cout << "max : " << fixed::max(a, b) << std::endl;
	}
	{
	std::cout << std::endl;
	fixed a(42);
	fixed b(48.5f);

	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << "a > b : " << (a > b ? "True":"False") << std::endl;
	std::cout << "a >= b : " << (a >= b ? "True":"False") << std::endl;
	std::cout << "a < b : " << (a < b ? "True":"False") << std::endl;
	std::cout << "a <= b : " << (a <= b ? "True":"False") << std::endl;
	std::cout << "a == b : " << (a == b ? "True":"False") << std::endl;
	std::cout << "a != b : " << (a != b ? "True":"False") << std::endl;
	std::cout << "a + b : " << a + b << std::endl;
	std::cout << "a - b : " << a - b << std::endl;
	std::cout << "a * b : " << a * b << std::endl;
	std::cout << "a / b : " << a / b << std::endl;
	std::cout << "max : " << fixed::max(a, b) << std::endl;
	std::cout << "min : " << fixed::min(a, b) << std::endl;
	std::cout << "++a : " << ++a << std::endl;
	std::cout << "a++ : " << a++ << std::endl;
	std::cout << "a-- : " << a-- << std::endl;
	std::cout << "--a : " << --a << std::endl;
	std::cout << "a : " << a << std::endl;
	}
}