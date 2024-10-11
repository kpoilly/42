/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 08:46:03 by kpoilly           #+#    #+#             */
/*   Updated: 2024/10/10 15:39:21 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	public:
		Array(): _initSize(0), _size(0)
		{
			this->_array = new T[this->_size];
		};
		Array(unsigned int n): _initSize(n), _size(n) 
		{
			this->_array = new T[this->_size];
		};
		Array(const Array& copy)
		{
			this->_array = NULL;
			*this = copy;
		};
		~Array()
		{
			if (this->_array)
				delete[]this->_array;
		};
		
		Array &operator=(const Array& copy)
		{
			if (this->_array)
				delete [] this->_array;
			if (copy.size())
			{
				this->_size = copy.size();
				this->_array = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; i++)
					this->_array[i] = copy._array[i];
			}
			return (*this);
		};
		T &operator[](unsigned int i)
		{
			if (i < 0 || i >= this->_size || !this->_array)
				throw IndexOutOfBoundException();
			return (this->_array[i]);
		};

		unsigned int size() const {return(this->_size);};

		class IndexOutOfBoundException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{return "Array::IndexOutOfBound";};
		};
		
	private:
		unsigned int _initSize;
		unsigned int _size;
		T* _array;
		
};

#endif