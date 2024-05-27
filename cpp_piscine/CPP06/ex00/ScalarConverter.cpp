/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:03:52 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/27 14:53:24 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){};
ScalarConverter::ScalarConverter(const ScalarConverter& copy){(void)copy;};
ScalarConverter::~ScalarConverter(){};

static bool	isPseudo(std::string str)
{
	return (str == "-inf" || str == "+inf" || str == "nan");
}

static void toChar(std::string str)
{
	std::cout << "char: ";
	if (isPseudo(str))
	{
		std::cout << "impossible." << std::endl;
		return ;
	}
	long	value = stoi(str);
	if(value < 0 || value > 255)
		std::cout << "impossible." << std::endl;
	else if (value == 0 || value > 127)
		std::cout << "Non displayable." << std::endl;
	else
		std::cout << static_cast<char>(value) << std::endl;

};

static void toInt(std::string str)
{	
	std::cout << "int: ";
	if (isPseudo(str) || str.size() <= 0)
	{
		std::cout << "impossible." << std::endl;
		return ;
	}
	long	value = stoi(str);
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "impossible." << std::endl;
	else
		std::cout << value << std::endl;
};

static void toFloat(std::string str)
{
	double	value = stof(str);
	std::cout << "float: ";
	if(str.size() <= 0 || value < std::numeric_limits<float>::lowest() || value > std::numeric_limits<float>::max())
		std::cout << "impossible." << std::endl;
	else
		{
			std::cout.setf(std::ios::fixed);
			std::cout << std::setprecision(1) << value << "f" << std::endl;
		}
};

static void toDouble(std::string str)
{
	double value = stod(str);
	std::cout << "double: ";
	if(str.size() <= 0)
		std::cout << "impossible." << std::endl;
	else
		std::cout << value << std::endl;
};

void ScalarConverter::convert(std::string literal)
{
	if (literal.empty())
		return ;
	//int	type;
	std::string	types[4] = {"char", "int", "float", "double"};
	void (*funcs[])(std::string) = {toChar, toInt, toFloat, toDouble};
	for (int i = 0; i < 4; i++)
		funcs[i](literal);
};
