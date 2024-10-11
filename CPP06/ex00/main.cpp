/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:03:56 by kpoilly           #+#    #+#             */
/*   Updated: 2024/09/25 19:06:41 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{	
	if (ac == 2)
	{
		std::string arg = av[1];
		std::cout << "\033[1;30mstr: " << arg << "\033[0m" << std::endl;
		ScalarConverter::convert(arg);
	}
	else if (ac == 1)
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
	else
	{	
		std::cout << "\033[1;31mError.\nInvalid arguments.\033[0m" << std::endl;
			return 42;
	}
	return 0;
}