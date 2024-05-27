/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:03:54 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/27 14:26:39 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <limits>

class ScalarConverter
{
	public:
		~ScalarConverter();
		static void convert(std::string literal);
		
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
};

#endif