/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:35:10 by kpoilly           #+#    #+#             */
/*   Updated: 2024/06/10 11:11:51 by kpoilly          ###   ########.fr       */
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
}

bool check_error(std::string input)
{
	if (input.find_first_not_of("0123456789+-/* ") != std::string::npos
		|| !is_op(input[input.size() - 1]))
		return true;
	if (!valid_number(input[0]) || !valid_number(input[2]))
		return true;
	int	count = 0;
	for (unsigned long i = 4; i < input.size(); i++)
	{
		if (input[i] != ' ')
			count++;
		else if (!(i % 2))
			return true;
		if (input[i] != ' ' && ((!(count % 2) && !valid_number(input[i]))
			|| (count % 2 && (input[i] <= '9' && input[i] >= '0'))))
			return true;
	}
	return false;
};