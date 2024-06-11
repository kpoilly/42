/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:03:52 by kpoilly           #+#    #+#             */
/*   Updated: 2024/06/11 09:37:01 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){};
ScalarConverter::ScalarConverter(const ScalarConverter& copy){(void)copy;};
ScalarConverter::~ScalarConverter(){};

static bool	isPseudof(std::string str)
{
	return (str == "-inff" || str == "+inff");
}

static bool	isPseudo(std::string str)
{
	return (str == "-inf" || str == "+inf" || str == "nan");
}

static void toChar(std::string str, long double value)
{
	std::cout << "char: ";
	if (isPseudo(str) || isPseudof(str))
	{
		std::cout << "impossible." << std::endl;
		return ;
	}
	if(value < 0 || value > 255)
		std::cout << "impossible." << std::endl;
	else if (value == 0 || value > 127)
		std::cout << "Non displayable." << std::endl;
	else
		std::cout << static_cast<char>(value) << std::endl;

};

static void toInt(std::string str, long double value)
{	
	std::cout << "int: ";
	if (isPseudo(str) || isPseudof(str) || str.size() <= 0)
	{
		std::cout << "impossible." << std::endl;
		return ;
	}
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "impossible." << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
};

static void toFloat(std::string str, long double value)
{
	std::cout << "float: ";
	if(str.size() <= 0 || ((value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())))
		std::cout << "impossible." << std::endl;
	else if (isPseudof(str))
		std::cout << str << std::endl;
	else if (isPseudo(str))
		std::cout << str + "f" << std::endl;
	else
		{
			std::cout.setf(std::ios::fixed);
			std::cout << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
		}
};

static void toDouble(std::string str, long double value)
{
	std::cout << "double: ";
	if(str.size() <= 0 || ((value < -std::numeric_limits<double>::max() || value > std::numeric_limits<double>::max())))
		std::cout << "impossible." << std::endl;
	else if (isPseudo(str))
		std::cout << str << std::endl;
	else if (isPseudof(str))
		std::cout << str.substr(0, str.size() - 1) << std::endl;
	else
		std::cout << std::setprecision(5) << value << std::endl;
};

void ScalarConverter::convert(std::string literal)
{
	if (literal.empty())
		return ;

	void (*funcs[])(std::string, long double) = {toChar, toInt, toFloat, toDouble};
	std::stringstream ss(literal);
	long double ld;
	ss >> ld;
	
	for (int i = 0; i < 4; i++)
			funcs[i](literal, ld);
};
