/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:57:57 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/31 12:43:15 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

# include <iostream>

class NoOccurenceFoundException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{return "EasyFind::NoOccurenceFound";};
};

template <typename T>

int easyfind(T &container, int occur)
{
	try
	{
		for (unsigned int i = 0; i < container.size(); i++)
			if (container[i] == occur)
				return (i);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	throw NoOccurenceFoundException();
	return(-1);
}

#endif