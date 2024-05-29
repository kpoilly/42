/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:03:52 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/29 10:31:59 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){};
ScalarConverter::ScalarConverter(const ScalarConverter& copy){(void)copy;};
ScalarConverter::~ScalarConverter(){};

static bool	isPseudof(std::string str)
{
	return (str == "-inff" || str == "+inff" || str == "nan");
}

static bool	isPseudo(std::string str)
{
	return (str == "-inf" || str == "+inf" || isPseudof(str));
}

static void toChar(std::string str)
{
	std::cout << "char: ";
	if (isPseudo(str))
	{
		std::cout << "impossible." << std::endl;
		return ;
	}
	long	value;
	std::istringstream(str) >> value;
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
	long	value;
	std::istringstream(str) >> value;
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "impossible." << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
};

static void toFloat(std::string str)
{
	double	value = atof(str.c_str());
	std::cout << "float: ";
	if(str.size() <= 0 || ((value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max()) && !isPseudof(str)))
		std::cout << "impossible." << std::endl;
	else
		{
			std::cout.setf(std::ios::fixed);
			std::cout << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
		}
};

static void toDouble(std::string str)
{
	long double value = atof(str.c_str());
	std::cout << "double: ";
	if(str.size() <= 0 || ((value < -std::numeric_limits<double>::max() || value > std::numeric_limits<double>::max()) && !isPseudo(str)))
		std::cout << "impossible." << std::endl;
	else
		std::cout << std::setprecision(5) << value << std::endl;
};

void ScalarConverter::convert(std::string literal, int type)
{
	if (literal.empty())
		return ;

	std::string	types[4] = {"char", "int", "float", "double"};
	//int	type = getType(literal);
	void (*funcs[])(std::string) = {toChar, toInt, toFloat, toDouble};
	
	if (type == 0)
	{
		std::ostringstream oss;
		oss << static_cast<int>(literal[0]);
		literal = oss.str();
	}
	for (int i = 0; i < 4; i++)
	{
		if (i != type)
			funcs[i](literal);
		else
			std::cout << types[type] << ": " << literal << std::endl;
	}
};
