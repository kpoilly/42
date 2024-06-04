/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:38:12 by kpoilly           #+#    #+#             */
/*   Updated: 2024/06/04 12:55:01 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _size(0), _cap(0)
{this->_array = NULL;};
Span::Span(int N): _size(0), _cap(N)
{this->_array = new int [N];};
Span::~Span()
{delete [] this->_array;};

void	Span::addNumber(int num)
{
	if (this->_size >= this->_cap)
		throw SpanFullException();
	this->_array[this->_size++] = num;
};

int		Span::shortestSpan()
{
	if (this->_size <= 1)
		throw SpanEmptyException();
	int	span = this->longestSpan();
	for(int i =0; i < this->_size; i++)
	{
		for(int j = 0; j < this->_size; j++)
			if (span > (this->_array[i] - this->_array[j])
				&& (this->_array[i] - this->_array[j]) > 0)
				span = (this->_array[i] - this->_array[j]);
	}
	return (span);
};
int		Span::longestSpan()
{
	if (this->_size <= 1)
		throw SpanEmptyException();
	return (this->getMax() - this->getMin());
};

int		Span::getMax()
{
	if (this->_size <= 1)
		throw SpanEmptyException();
	int	max = this->_array[0];
	for (int i = 0; i < this->_size; i++)
		if (this->_array[i] > max)
			max = this->_array[i];
	return (max);
};

int		Span::getMin()
{
	if (this->_size <= 1)
		throw SpanEmptyException();
	int	min = this->_array[0];
	for (int i = 0; i < this->_size; i++)
		if (this->_array[i] < min)
			min = this->_array[i];
	return (min);
};
