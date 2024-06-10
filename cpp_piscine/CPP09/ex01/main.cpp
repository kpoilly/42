/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:34:48 by kpoilly           #+#    #+#             */
/*   Updated: 2024/06/10 11:02:32 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	calc(int a, int b, char op)
{
	std::string ops = "+-/*";
	unsigned long i = 0;
	
	for (; i < ops.size(); i++)
		if (ops[i] == op)
			break ;
	
	switch (i)
	{
		case 0:
			return(a + b);
		case 1:
			return(a - b);
		case 2:
			return(a / b);
		case 3:
			return(a * b);
	}
	throw std::string("pb operateur");
	return (0);
}

int	main(int ac, char** av)
{
	if (ac != 2 || check_error(av[1]))
	{
		std::cerr << "Error. Invalid input." << std::endl;
		return 1;
	}
	
	std::stack<int> stack;
	std::string input(av[1]);
	int			tocalc = 1;
	
	stack.push(input[0] - '0');
	for (unsigned long i = 2; i < input.size(); i++)
	{
		if (valid_number(input[i]))
			tocalc = input[i] - '0';
		else if (input[i] != ' ')
			stack.push(calc(stack.top(), tocalc, input[i]));
	}
	std::cout << stack.top() << std::endl;
};