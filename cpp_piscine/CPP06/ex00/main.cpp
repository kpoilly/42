/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:03:56 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/29 09:55:25 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(void)
{	
	std::cout << "\033[1;30mstr: '\033[0m" << std::endl;
	ScalarConverter::convert("'", 0);
	std::cout << "\n\033[1;30mstr: 0\033[0m" << std::endl;
	ScalarConverter::convert("0", 1);
	std::cout << "\n\033[1;30mstr: 42.0f\033[0m" << std::endl;
	ScalarConverter::convert("42.0f", 2);
	std::cout << "\n\033[1;30mstr: -42\033[0m" << std::endl;
	ScalarConverter::convert("-42", 1);
	std::cout << "\n\033[1;30mstr: 42.422222222222222f\033[0m" << std::endl;
	ScalarConverter::convert("42.422222222222222f", 3);
	std::cout << "\n\033[1;30mstr: -inff\033[0m" << std::endl;
	ScalarConverter::convert("-inff", 2);
	std::cout << "\n\033[1;30mstr: +inff\033[0m" << std::endl;
	ScalarConverter::convert("+inff", 2);
	std::cout << "\n\033[1;30mstr: nan\033[0m" << std::endl;
	ScalarConverter::convert("nan", 2);
	std::cout << "\n\033[1;30mstr: -inf\033[0m" << std::endl;
	ScalarConverter::convert("-inf", 3);
	std::cout << "\n\033[1;30mstr: +inf\033[0m" << std::endl;
	ScalarConverter::convert("+inf", 3);
}