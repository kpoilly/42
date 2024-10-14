/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:57:57 by kpoilly           #+#    #+#             */
/*   Updated: 2024/10/11 11:14:06 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

# include <iostream>
# include <algorithm>

class NoOccurenceFoundException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{return "EasyFind::NoOccurenceFound";};
};

template <typename T>

void easyfind(T &container, int occur)
{
	try
	{
		typename T::iterator found = std::find(container.begin(), container.end(), occur);
		if (found == container.end())
			throw NoOccurenceFoundException();
		std::cout << "\033[1;32m" << occur << " has been found inside the container ! :D\033[0m" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

#endif