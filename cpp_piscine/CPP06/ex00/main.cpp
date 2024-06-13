/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:03:56 by kpoilly           #+#    #+#             */
/*   Updated: 2024/06/13 09:51:29 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(void)
{	
	std::cout << "\033[1;30mstr: '\033[0m" << std::endl;
	ScalarConverter::convert("'");
	std::cout << "\n\033[1;30mstr: 0\033[0m" << std::endl;
	ScalarConverter::convert("0");
	std::cout << "\n\033[1;30mstr: 42.0f\033[0m" << std::endl;
	ScalarConverter::convert("42.0f");
	std::cout << "\n\033[1;30mstr: -42\033[0m" << std::endl;
	ScalarConverter::convert("-42");
	std::cout << "\n\033[1;30mstr: 42.422222222222222f\033[0m" << std::endl;
	ScalarConverter::convert("42.422222222222222f");
	std::cout << "\n\033[1;30mstr: -inff\033[0m" << std::endl;
	ScalarConverter::convert("-inff");
	std::cout << "\n\033[1;30mstr: +inff\033[0m" << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << "\n\033[1;30mstr: nan\033[0m" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << "\n\033[1;30mstr: -inf\033[0m" << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << "\n\033[1;30mstr: +inf\033[0m" << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << "\n\033[1;30mstr: 000\033[0m" << std::endl;
	ScalarConverter::convert("000");
	std::cout << "\n\033[1;30mstr: ..\033[0m" << std::endl;
	ScalarConverter::convert("..");
}