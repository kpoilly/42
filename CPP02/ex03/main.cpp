/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:52:10 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/10 07:17:31 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	point a(5, 2);
	point b(8, 12);
	point c(3, 7);
	
	point point1(5,7);
	point point2(3,12);

	std::cout << "p1 in ? " << bsp(a, b, c, point1) << std::endl;
	std::cout << "p2 in ? " << bsp(a, b, c, point2) << std::endl;
}