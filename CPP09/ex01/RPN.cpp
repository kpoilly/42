/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:35:10 by kpoilly           #+#    #+#             */
/*   Updated: 2024/06/10 14:14:53 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool valid_number(char c)
{
	return !(c > '9' || c < '0' || (c - '0') < 0 || (c - '0') > 9);
};

bool is_op(char c)
{
	return (c == '+' || c == '-' || c == '/' || c == '*');
};

bool check_error(std::string input)
{
	if (input.find_first_not_of("0123456789+-/* ") != std::string::npos
		|| !is_op(input[input.size() - 1]))
		return true;
	if (!valid_number(input[0]) || !valid_number(input[2]))
		return true;
	for (unsigned long i = 1; i < input.size(); i++)
	{
		if (((i % 2) && input[i] != ' ') || (!(i % 2) && input[i] == ' '))
			return true;
		else if (!(i % 2) && !is_op(input[i]) && !valid_number(input[i]))
			return true;
	}
	return false;
};