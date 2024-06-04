/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:38:12 by kpoilly           #+#    #+#             */
/*   Updated: 2024/06/04 16:32:57 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _array(0), _cap(0)
{}
Span::Span(int N): _array(N), _cap(N)
{};
Span::~Span()
{this->_array.clear();};

void	Span::addNumber(int num)
{
	if (this->_array.size() > this->_array.capacity())
		throw SpanFullException();
	this->_array[this->_array.size() - (this->_cap--)] = num;

};

int		Span::shortestSpan()
{
	if (this->_array.size() <= 1)
		throw SpanEmptyException();
	int	span = this->longestSpan();
	for(unsigned long i =0; i < this->_array.size(); i++)
	{
		for(unsigned long j = 0; j < this->_array.size(); j++)
			if (span > (this->_array[i] - this->_array[j])
				&& (this->_array[i] - this->_array[j]) > 0)
				span = (this->_array[i] - this->_array[j]);
	}
	return (span);
};
int		Span::longestSpan()
{
	if (this->_array.size() <= 1)
		throw SpanEmptyException();
	return (*std::max_element(this->_array.begin(), this->_array.end()) - *std::min_element(this->_array.begin(), this->_array.end()));
};
