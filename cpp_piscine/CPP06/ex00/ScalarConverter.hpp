/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:03:54 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/29 09:52:07 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <limits>
# include <fstream>
# include <sstream>
# include <stdlib.h>

class ScalarConverter
{
	public:
		~ScalarConverter();
		static void convert(std::string literal, int type);
		
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
};

#endif