/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:41:40 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/29 10:51:37 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T> void swap(T &x, T &y)
{
	T temp = x;
	x = y;
	y = temp;
};
template <typename T> const T &max(const T &x, const T &y)
{
	return ((x > y) ? x : y);	
};

template <typename T> const T &min(const T &x, const T &y)
{
	return ((x < y) ? x : y);	
};

#endif