/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:52:20 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/18 09:03:44 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <math.h>

class fixed
{
	private:
		int value;
		static const int frac = 8;

	public:
		fixed(void);
		fixed(const int nb);
		fixed(const float nb);
		fixed(const fixed& nb);
		~fixed();
		
		fixed& operator= (const fixed& nb);
		friend bool operator> (const fixed& a, const fixed& b);
		friend bool operator>= (const fixed& a, const fixed& b);
		friend bool operator< (const fixed& a, const fixed& b);
		friend bool operator<= (const fixed& a, const fixed& b);
		friend bool operator== (const fixed& a, const fixed& b);
		friend bool operator!= (const fixed& a, const fixed& b);
		friend fixed& operator+ (const fixed& a, const fixed& b);
		friend fixed& operator- (const fixed& a, const fixed& b);
		friend fixed& operator* (const fixed& a, const fixed& b);
		friend fixed& operator/ (const fixed& a, const fixed& b);
		friend std::ostream& operator<<(std::ostream& os, const fixed& nb);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		
		float toFloat(void) const;
		int toInt(void) const;
		fixed& min (fixed& a, fixed& b);
		fixed& min (const fixed& a, const fixed& b) const;
		fixed& max (fixed& a, fixed& b);
		fixed& max (const fixed& a, const fixed& b) const;
};

#endif