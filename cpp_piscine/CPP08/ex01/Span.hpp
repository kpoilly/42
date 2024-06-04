/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:37:44 by kpoilly           #+#    #+#             */
/*   Updated: 2024/06/04 16:38:56 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class Span
{
	public:
		Span();
		Span(int N);
		~Span();
		
		void	addNumber(int num);
		void	addNumber(std::vector<int> toAdd);
		int		shortestSpan();
		int		longestSpan();

	private:
		std::vector<int>	_array;
		unsigned long		_cap;

		class SpanFullException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{return "Span::ReachedMaximumCapacity";};
		};

		class SpanEmptyException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{return "Span::SpanIsEmpty";};
		};
};

#endif