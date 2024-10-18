/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:34:48 by kpoilly           #+#    #+#             */
/*   Updated: 2024/10/18 14:26:22 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	calc(int a, int b, char op)
{
	std::cout << a << ' ' << op << ' ' << b << " = " << std::endl;
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
	throw std::string("Calc::UnknownOperator");
	return (0);
};

int	main(int ac, char** av)
{
	if (ac != 2 || check_error(av[1]))
	{
		std::cerr << "Error. Invalid input." << std::endl;
		return 1;
	}
	
	std::stack<int>		numbers;
	std::stack<char>	ops;
	std::string 	input(av[1]);
	int				tocalc, res;
	
	int i = input.size() - 1;
	for (; i >= 0; i--)
	{
		if (input[i] && valid_number(input[i]))
			numbers.push(input[i] - '0');
		if (input[input.size() - 1 - i] && is_op(input[input.size() - 1 - i]))
		{
			ops.push(input[input.size()- 1 - i]);
			std::cout << input[input.size()- 1 - i] << " added to stack ops" << std::endl;
		}
	}

	tocalc = numbers.top();
	numbers.pop();
	
	if (numbers.size() != ops.size())
	{
		std::cerr << "Error. Invalid input. (2)" << std::endl;
		return 1;
	}

	for (size_t i = 0; i < numbers.size(); i++)
	{
		res = calc(tocalc, numbers.top(), ops.top());
		numbers.pop();
		ops.pop();
		std::cout << res << std::endl;
	}

	std::cout << res << std::endl;
};
