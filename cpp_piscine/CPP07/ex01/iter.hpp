/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:55:03 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/29 11:28:06 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void	iter(const T *arr, int length, void (*f)(const T))
{
	for (int i = 0; i < length; i++)
		f(arr[i]);
}

template <typename T>
void	print(const T)
{
	std::cout << T << std::endl;
}

#endif