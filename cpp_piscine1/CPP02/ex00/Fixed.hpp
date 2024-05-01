/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:52:20 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/01 13:44:24 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class fixed
{
	private:
		int _value;
		static const int _frac = 8;

	public:
		fixed();
		fixed(fixed& nb);
		fixed& operator= (fixed& nb);
		~fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif