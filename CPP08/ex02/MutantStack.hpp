/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 08:40:14 by kpoilly           #+#    #+#             */
/*   Updated: 2024/06/05 09:22:20 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <iostream>
# include <stack>


template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(): std::stack<T>(){};
		~MutantStack(){};

		MutantStack(MutantStack& copy): std::stack<T>()
		{*this = copy;};
		MutantStack& operator=(MutantStack& copy)
		{
			std::stack<T>::operator=(copy);
			return (*this);
		};

		// T &operator[](unsigned int i)
		// {
		// 	T index;
		// 	if (i < 0 || i > this->_size)
		// 		throw IndexOutOfBoundException();
				
		// 	return (this->_stack[i]);
		// };
		
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(){return (std::stack<T>::c.begin());};
		iterator end(){return (std::stack<T>::c.end());};
};

#endif
