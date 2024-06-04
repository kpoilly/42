/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:37:44 by kpoilly           #+#    #+#             */
/*   Updated: 2024/06/04 12:43:10 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>

class Span
{
	public:
		Span();
		Span(int N);
		~Span();
		
		void	addNumber(int num);
		int		shortestSpan();
		int		longestSpan();

		int		getMax();
		int		getMin();

	private:
		int*	_array;
		int		_size;
		int		_cap;

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