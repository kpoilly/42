/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 08:46:03 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/31 10:06:57 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	public:
		Array(): _initSize(0), _size(0), _array(NULL) 
		{};
		Array(unsigned int n): _initSize(n), _size(n) 
		{
			this->_array = new T[n];
		};
		Array(const Array& copy){*this = copy;};
		~Array(){delete[]this->_array;};

		unsigned int size(){return(this->_size);};
		
		Array &operator=(const Array& copy)
		{
			this->_size = copy.size();
			delete [] this->_array;
			this->_array = new T[this->_size];
			for (int i = 0; i < this->_size; i++)
				this->_array[i] = copy[i];
		};
		T &operator[](unsigned int i)
		{
			if (i < 0 || i > this->_size)
				throw IndexOutOfBoundException();
			return (this->_array[i]);
		};

	private:
		unsigned int _initSize;
		unsigned int _size;
		T* _array;
		
		class IndexOutOfBoundException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{return "Array::IndexOutOfBound";};
		};
};

#endif