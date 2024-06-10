/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:34:48 by kpoilly           #+#    #+#             */
/*   Updated: 2024/06/10 11:16:23 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	calc(int a, int b, char op)
{
	switch (op)
	{
		case '+':
			return(a + b);
		case '-':
			return(a - b);
		case '/':
			return(a / b);
		case '*':
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