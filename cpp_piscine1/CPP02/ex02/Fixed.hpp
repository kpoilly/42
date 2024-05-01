/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:52:20 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/01 13:45:56 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <math.h>

class fixed
{
	private:
		int _value;
		static const int frac = 8;

	public:
		fixed(void);
		fixed(const int nb);
		fixed(const float nb);
		fixed(const fixed& nb);
		~fixed();
		
		fixed& operator= (const fixed& nb);
		bool operator> (const fixed& other);
		bool operator>= (const fixed& other);
		bool operator< (const fixed& other);
		bool operator<= (const fixed& other);
		bool operator== (const fixed& other);
		bool operator!= (const fixed& other);
		fixed& operator+ (const fixed& other);
		fixed& operator- (const fixed& other);
		fixed& operator* (const fixed& other);
		fixed& operator/ (const fixed& other);
		fixed& operator++ ();
		fixed& operator++ (int);
		fixed& operator-- ();
		fixed& operator-- (int);
		
		int getRawBits(void) const;
		void setRawBits(int const raw);
		
		float toFloat(void) const;
		int toInt(void) const;
		int toFixed(float nb);
		static fixed& min (fixed& a, fixed& b);
		static const fixed& min (const fixed& a, const fixed& b);
		static fixed& max (fixed& a, fixed& b);
		static const fixed& max (const fixed& a, const fixed& b);
};

std::ostream& operator<<(std::ostream& os, const fixed& nb);

#endif