/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:34:48 by kpoilly           #+#    #+#             */
/*   Updated: 2024/10/18 18:44:58 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	calc(int a, int b, char op)
{
	//std::cout << a << ' ' << op << ' ' << b << " = ";
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
	int				res;
	
	int i = input.size() - 1;
	for (; i >= 0; i--)
	{
		if (input[i] && valid_number(input[i]))
			numbers.push(input[i] - '0');
		else if (input[i] && is_op(input[i]))
			ops.push(input[i]);
	}

	res = numbers.top();
	numbers.pop();
	
	if (numbers.size() != ops.size())
	{
		std::cerr << "Error. Invalid input." << std::endl;
		return 1;
	}

	size_t nbops = ops.size();
	for (size_t i = 0; i < nbops; i++)
	{
		res = calc(res, numbers.top(), ops.top());
		numbers.pop();
		ops.pop();
		//std::cout << res << std::endl;
	}

	std::cout << res << std::endl;
};
